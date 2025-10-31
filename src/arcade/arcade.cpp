#include "meta/headers.hpp"


/***********************************************************************
     * Arcade
     * constructor

***********************************************************************/
ach::Arcade::Arcade(ach::ArcadeGame _game, bool select)
{
	score   = 0;
	active  = true;
	updated = true;
	game    = _game;
	offset  = sf::Vector2f(ARCADE_OFFSET_X, ARCADE_OFFSET_Y);
	caption = str_utf8(pair_get_string(game, pairArcadeName));
	high    = records->getHighscore(game);
	best    = records->getBestScore(game);
	rank    = records->getRankScore(game);

	tex     = new sf::RenderTexture();
	spr     = new sf::Sprite();
	text    = new sf::Text();
	border  = new ach::RectangleShape(sf::Vector2f(ARCADE_BORDER_WIDTH, ARCADE_BORDER_HEIGHT));

	pick    = db->getSound(json_object_get_branch_string(dm->data, "Meta.Arcade.Misc.Pick"))->snd;
	over    = db->getSound(json_object_get_branch_string(dm->data, "Meta.Arcade.Misc.Over"))->snd;

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

	if (select)
		caption = "< " + caption + " >";

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
		case ach::ArcadeState::asTitle:
		case ach::ArcadeState::asGameOver:
			pulse.update(true);
			sync();
		break;


		case ach::ArcadeState::asPlay:
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
		case ach::ArcadeState::asTitle:
			renderValue("HIGH SCORE"  ,   5, high, true );
			renderValue("RANK"        ,  25, rank, false);
			renderValue("WORLD RECORD", 215, best, false);

			renderTitle(caption);
			renderPress();
		break;


		case ach::ArcadeState::asGameOver:
			renderValue("HIGH SCORE"  ,   5, high, true );
			renderValue("RANK"        ,  25, rank, false);
			renderValue("WORLD RECORD", 215, best, false);

			renderTitle("GAME OVER");
		break;


		case ach::ArcadeState::asPlay:
			renderValue("SCORE", 5, score, true);
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
     * renderPress

***********************************************************************/
void ach::Arcade::renderPress()
{
	if (game == ach::ArcadeGame::agNone)
		return;

	text_draw(text, "press start button", 0, 170, ARCADE_SIZE, ach::TextAlign::taCenter, tex);
}



/***********************************************************************
     * Arcade
     * renderTitle

***********************************************************************/
void ach::Arcade::renderTitle(sf::String name)
{
	text->setCharacterSize(theme->arcade->size * 1.5f);

	if (pulse.active)
		text_draw(text, name, 0, 90, ARCADE_SIZE, ach::TextAlign::taCenter, tex);

	text->setCharacterSize(theme->arcade->size);
}



/***********************************************************************
     * Arcade
     * renderValue

***********************************************************************/
void ach::Arcade::renderValue(sf::String name, int y, int value, bool zero)
{
	if (game == ach::ArcadeGame::agNone)
		return;

	if (!zero && !value)
		return;

	text_draw(text, name                 , 5, y, ARCADE_SIZE - 10, ach::TextAlign::taLeft , tex);
	text_draw(text, std::to_string(value), 5, y, ARCADE_SIZE - 10, ach::TextAlign::taRight, tex);
}



/***********************************************************************
     * Arcade
     * controls

***********************************************************************/
void ach::Arcade::controls()
{
	switch (state)
	{
		case ach::ArcadeState::asTitle:
			if      (ctrl->keys[ach::ControlAction::caJump].pressed) init();
			else if (ctrl->keys[ach::ControlAction::caMenu].pressed) quit();
		break;


		case ach::ArcadeState::asGameOver:
			if      (ctrl->keys[ach::ControlAction::caJump].pressed) reset();
			else if (ctrl->keys[ach::ControlAction::caMenu].pressed) quit();
		break;


		case ach::ArcadeState::asPlay:
			if      (ctrl->keys[ach::ControlAction::caMenu].pressed) stop();
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
	state = ach::ArcadeState::asPlay;

	prepare();
	sm->play(pick);
}



/***********************************************************************
     * Arcade
     * quit

***********************************************************************/
void ach::Arcade::quit()
{
	active = false;

	sm->play(over);
}



/***********************************************************************
     * Arcade
     * reset

***********************************************************************/
void ach::Arcade::reset()
{
	state = ach::ArcadeState::asTitle;
	score = 0;

	pulse.set(1.0f);
	sm->play(pick);
}



/***********************************************************************
     * Arcade
     * stop

***********************************************************************/
void ach::Arcade::stop()
{
	highscore();
	reset();
}



/***********************************************************************
     * Arcade
     * gameover

***********************************************************************/
void ach::Arcade::gameover()
{
	state = ach::ArcadeState::asGameOver;

	pulse.set(1.0f);
	sm->play(over);
	highscore();
}



/***********************************************************************
     * Arcade
     * highscore

***********************************************************************/
void ach::Arcade::highscore()
{
	records->setHighscore(game, score);

	updated = false;
	high    = records->getHighscore(game);
}



/***********************************************************************
     * Arcade
     * sync

***********************************************************************/
void ach::Arcade::sync()
{
	if (updated)
		return;

	if (!records->update(game))
		return;

	updated = true;
	high    = records->getHighscore(game);
	best    = records->getBestScore(game);
	rank    = records->getRankScore(game);
}



/***********************************************************************
     * Arcade
     * create

***********************************************************************/
ach::Arcade* ach::Arcade::create(ach::ArcadeGame game, bool select)
{
	switch (game)
	{
		case ach::ArcadeGame::agNone    : return new ach::ArcadeNone    (select);
		case ach::ArcadeGame::agBrickOut: return new ach::ArcadeBrickOut(select);
		case ach::ArcadeGame::agHexagon : return new ach::ArcadeHexagon (select);
		case ach::ArcadeGame::agRace    : return new ach::ArcadeRace    (select);
		case ach::ArcadeGame::agSnake   : return new ach::ArcadeSnake   (select);
		case ach::ArcadeGame::agSimon   : return new ach::ArcadeSimon   (select);
		case ach::ArcadeGame::agTetris  : return new ach::ArcadeTetris  (select);
		case ach::ArcadeGame::agCount   : return new ach::ArcadeNone    (select);
	}

	return new ach::ArcadeNone(select);
}
