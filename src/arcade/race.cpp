#include "meta/headers.hpp"


/***********************************************************************
     * ArcadeRace
     * constructor

***********************************************************************/
ach::ArcadeRace::ArcadeRace(bool select) : Arcade(ach::ArcadeGame::agRace, select)
{
	square = new sf::RectangleShape(sf::Vector2f(ARCADE_SQUARE - 1, ARCADE_SQUARE - 1));

	ticker.set(0.02f);
	stepper.set(0.02f);
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

	for (int i = 0; i < ARCADE_RACE_CARS; i++)
		cars[i] = sf::Vector2i(0, 0);

	for (int i = 0; i < ARCADE_RACE_CARS; i++)
		gen();

	for (int i = 0; i < ARCADE_RACE_CARS; i++)
		cars[i].x += ARCADE_RACE_LENGTH;
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

	step -= stepper.update(true);

	if (step < 0)
		step = ARCADE_RACE_STEP - 1;

	if (collide())
		gameover();
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

	for (int i = 0; i < ARCADE_RACE_CARS; i++)
		car(cars[i].y, cars[i].x, sf::Color::White);
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
	for (int i = 0; i < ARCADE_RACE_CARS; i++)
		cars[i].x--;

	if (cars[0].x < -ARCADE_RACE_WIDTH)
	{
		score.increase();

		gen();
	}
}



/***********************************************************************
     * ArcadeRace
     * gen

***********************************************************************/
void ach::ArcadeRace::gen()
{
	for (int i = 0; i < ARCADE_RACE_CARS - 1; i++)
		cars[i] = cars[i + 1];

	cars[ARCADE_RACE_CARS - 1].y = rand() % 3;
	cars[ARCADE_RACE_CARS - 1].x = cars[ARCADE_RACE_CARS - 2].x + rand() % 8 + 10;
}



/***********************************************************************
     * ArcadeRace
     * collide

***********************************************************************/
bool ach::ArcadeRace::collide()
{
	if (cars[0].y != pos)
		return false;

	if (cars[0].x >  ARCADE_RACE_WIDTH + 1)
		return false;

	if (cars[0].x < -ARCADE_RACE_WIDTH + 1)
		return false;

	return true;
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
	if (pos.x >= ARCADE_RACE_LENGTH)
		return;

	square->setPosition(sf::Vector2f(pos.x * ARCADE_SQUARE, pos.y * ARCADE_SQUARE - ARCADE_SQUARE / 2.0f) + offset);
	square->setFillColor(color);

	tex->draw(*square);
}
