#include "meta/headers.hpp"


/***********************************************************************
     * Arcade
     * constructor

***********************************************************************/
ach::Arcade::Arcade()
{
	score  = 0;
	high   = 0;
	active = true;
	state  = ach::ArcadeState::Title;

	tex    = new sf::RenderTexture();
	spr    = new sf::Sprite();
	border = new ach::RectangleShape(sf::Vector2f(ARCADE_BORDER_WIDTH, ARCADE_BORDER_HEIGHT));

	border->style(theme->menu.box);
	border->setPosition(sf::Vector2f(ARCADE_OFFSET_X - 1, ARCADE_OFFSET_Y - 1));
	border->setFillColor(sf::Color::Transparent);
	border->setOutlineThickness(1);

	tex->create(ARCADE_SIZE, ARCADE_SIZE);
	tex->setRepeated(false);
	tex->setActive(true);
	tex->setSmooth(false);

	spr->setTexture(tex->getTexture());
}



/***********************************************************************
     * Arcade
     * destructor

***********************************************************************/
ach::Arcade::~Arcade()
{
	delete tex;
	delete spr;
	delete border;
}



/***********************************************************************
     * Arcade
     * update

***********************************************************************/
void ach::Arcade::update()
{
	process();
}



/***********************************************************************
     * Arcade
     * render

***********************************************************************/
void ach::Arcade::render()
{
	draw();
}



/***********************************************************************
     * Arcade
     * controls

***********************************************************************/
void ach::Arcade::controls()
{
	handle();
}



/***********************************************************************
     * Arcade
     * create

***********************************************************************/
ach::Arcade* ach::Arcade::create()
{
	return new ach::Arcade();
}
