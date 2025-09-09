#include "meta/headers.hpp"


/***********************************************************************
     * ArcadeRace
     * constructor

***********************************************************************/
ach::ArcadeRace::ArcadeRace(bool select) : Arcade(ach::ArcadeGame::Race, select)
{
	square = new sf::RectangleShape(sf::Vector2f(ARCADE_SQUARE - 1, ARCADE_SQUARE - 1));

	ticker.set(0.03f);
}



/***********************************************************************
     * ArcadeRace
     * destructor

***********************************************************************/
ach::ArcadeRace::~ArcadeRace()
{
	delete square;
}



/***********************************************************************
     * ArcadeRace
     * prepare

***********************************************************************/
void ach::ArcadeRace::prepare()
{
	pos  = 1;
	step = 0;
}



/***********************************************************************
     * ArcadeRace
     * process

***********************************************************************/
void ach::ArcadeRace::process()
{
	if (!ticker.update(true))
	{
		tick();
		ticker.reset();
	}
}



/***********************************************************************
     * ArcadeRace
     * draw

***********************************************************************/
void ach::ArcadeRace::draw()
{
	line(0, sf::Color::Red);
	line(1, sf::Color(100, 100, 100));
	line(2, sf::Color(100, 100, 100));
	line(3, sf::Color::Red);

	car(pos, 1, sf::Color::Green);
}



/***********************************************************************
     * ArcadeRace
     * handle

***********************************************************************/
void ach::ArcadeRace::handle()
{
	if (ctrl->keys[ach::ControlAction::caUp  ].pressed) pos--;
	if (ctrl->keys[ach::ControlAction::caDown].pressed) pos++;

	pos = interval_set(pos, 0, 2);
}



/***********************************************************************
     * ArcadeRace
     * tick

***********************************************************************/
void ach::ArcadeRace::tick()
{
	step--;

	if (step < 0)
		step = ARCADE_RACE_STEP - 1;
}



/***********************************************************************
     * ArcadeRace
     * car

***********************************************************************/
void ach::ArcadeRace::car(int line, int x, sf::Color color)
{
	sf::Vector2i p = sf::Vector2i(x, ARCADE_RACE_OFFSET + line * 6);

	tile(p + sf::Vector2i(0, 2), color);
	tile(p + sf::Vector2i(0, 4), color);
	tile(p + sf::Vector2i(1, 3), color);
	tile(p + sf::Vector2i(2, 2), color);
	tile(p + sf::Vector2i(2, 3), color);
	tile(p + sf::Vector2i(2, 4), color);
	tile(p + sf::Vector2i(3, 3), color);
}



/***********************************************************************
     * ArcadeRace
     * line

***********************************************************************/
void ach::ArcadeRace::line(int line, sf::Color color)
{
	int p = step;

	while (p < ARCADE_RACE_LENGTH)
	{
		tile(sf::Vector2i(p, ARCADE_RACE_OFFSET + line * 6), color);
		p += ARCADE_RACE_STEP;
	}
}



/***********************************************************************
     * ArcadeRace
     * tile

***********************************************************************/
void ach::ArcadeRace::tile(sf::Vector2i pos, sf::Color color)
{
	square->setPosition(sf::Vector2f(pos.x * ARCADE_SQUARE - ARCADE_SQUARE / 2.0f, pos.y * ARCADE_SQUARE) + offset);
	square->setFillColor(color);

	tex->draw(*square);
}
