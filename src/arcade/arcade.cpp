#include "meta/headers.hpp"


/***********************************************************************
     * Arcade
     * constructor

***********************************************************************/
ach::Arcade::Arcade(sf::String _caption)
{
	score   = 0;
	high    = 0;
	active  = true;
	visible = true;
	caption = _caption;

	tex     = new sf::RenderTexture();
	spr     = new sf::Sprite();
	text    = new sf::Text();
	border  = new ach::RectangleShape(sf::Vector2f(ARCADE_BORDER_WIDTH, ARCADE_BORDER_HEIGHT));

	text->setFont(*theme->arcade->font);
	text->setCharacterSize(theme->arcade->size);
	text->setFillColor(theme->arcade->color);

	border->style(theme->menu.box);
	border->setPosition(sf::Vector2f(ARCADE_OFFSET_X - 1, ARCADE_OFFSET_Y - 1));
	border->setFillColor(sf::Color::Transparent);
	border->setOutlineColor(sf::Color::White);
	border->setOutlineThickness(1);

	tex->create(ARCADE_SIZE, ARCADE_SIZE);
	tex->setRepeated(false);
	tex->setActive(true);
	tex->setSmooth(false);

	spr->setTexture(tex->getTexture());

	reset();
}



/***********************************************************************
     * Arcade
     * destructor

***********************************************************************/
ach::Arcade::~Arcade()
{
	delete tex;
	delete spr;
	delete text;
	delete border;
}



/***********************************************************************
     * Arcade
     * update

***********************************************************************/
void ach::Arcade::update()
{
	switch (state)
	{
		case ach::ArcadeState::Title:
		case ach::ArcadeState::GameOver:
			if (!timer.update(true))
			{
				timer.reset();

				visible = !visible;
			}
		break;


		case ach::ArcadeState::Play:
			process();
		break;
	}
}



/***********************************************************************
     * Arcade
     * render

***********************************************************************/
void ach::Arcade::render()
{
	tex->clear(sf::Color::Transparent);

	switch (state)
	{
		case ach::ArcadeState::Title:
			if (high)
				renderScore("HIGH SCORE", high);

			renderTitle(caption);
		break;


		case ach::ArcadeState::GameOver:
			renderScore("HIGH SCORE", high);
			renderTitle("GAME OVER");
		break;


		case ach::ArcadeState::Play:
			renderScore("SCORE", score);
			renderBorder();

			draw();
		break;
	}

	tex->display();
}



/***********************************************************************
     * Arcade
     * renderBorder

***********************************************************************/
void ach::Arcade::renderBorder()
{
	tex->draw(*border);
}



/***********************************************************************
     * Arcade
     * renderTitle

***********************************************************************/
void ach::Arcade::renderTitle(sf::String name)
{
	text->setCharacterSize(theme->arcade->size * 1.5f);

	if (visible)
		text_draw(text, name, 0, 100, ARCADE_SIZE, ach::TextAlign::taCenter, tex);

	text->setCharacterSize(theme->arcade->size);
}



/***********************************************************************
     * Arcade
     * renderScore

***********************************************************************/
void ach::Arcade::renderScore(sf::String name, int value)
{
	text_draw(text, name + " : " + std::to_string(value), 5, 5, ARCADE_SIZE - 10, ach::TextAlign::taRight, tex);
}



/***********************************************************************
     * Arcade
     * controls

***********************************************************************/
void ach::Arcade::controls()
{
	switch (state)
	{
		case ach::ArcadeState::Title:
			if      (ctrl->keys[ach::ControlAction::caJump].pressed) init();
			else if (ctrl->keys[ach::ControlAction::caMenu].pressed) quit();
		break;


		case ach::ArcadeState::GameOver:
			if      (ctrl->keys[ach::ControlAction::caJump].pressed) reset();
			else if (ctrl->keys[ach::ControlAction::caMenu].pressed) quit();
		break;


		case ach::ArcadeState::Play:
			if      (ctrl->keys[ach::ControlAction::caMenu].pressed) reset();
			else handle();
		break;
	}
}



/***********************************************************************
     * Arcade
     * init

***********************************************************************/
void ach::Arcade::init()
{
	state = ach::ArcadeState::Play;
}



/***********************************************************************
     * Arcade
     * quit

***********************************************************************/
void ach::Arcade::quit()
{
	active = false;
}



/***********************************************************************
     * Arcade
     * reset

***********************************************************************/
void ach::Arcade::reset()
{
	timer.set(1.0f);

	state   = ach::ArcadeState::Title;
	visible = true;
}



/***********************************************************************
     * Arcade
     * gameover

***********************************************************************/
void ach::Arcade::gameover()
{
	timer.set(1.0f);

	state   = ach::ArcadeState::GameOver;
	visible = true;
}



/***********************************************************************
     * Arcade
     * create

***********************************************************************/
ach::Arcade* ach::Arcade::create(ach::ArcadeGame game, bool select)
{
	sf::String _caption = pair_get_string(game, pairArcadeName);

	if (select)
		_caption = "< " + _caption + " >";

	switch (game)
	{
		case ach::ArcadeGame::None    : return new ach::ArcadeNone    (_caption);
		case ach::ArcadeGame::BrickOut: return new ach::ArcadeBrickOut(_caption);
		case ach::ArcadeGame::Hexagon : return new ach::ArcadeHexagon (_caption);
		case ach::ArcadeGame::Race    : return new ach::ArcadeRace    (_caption);
		case ach::ArcadeGame::Snake   : return new ach::ArcadeSnake   (_caption);
		case ach::ArcadeGame::Simon   : return new ach::ArcadeSimon   (_caption);
		case ach::ArcadeGame::Tetris  : return new ach::ArcadeTetris  (_caption);
		case ach::ArcadeGame::Count   : return new ach::ArcadeNone    (_caption);
	}

	return new ach::ArcadeNone(_caption);
}
