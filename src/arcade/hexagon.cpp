#include "meta/headers.hpp"


/***********************************************************************
     * ArcadeHexagon
     * constructor

***********************************************************************/
ach::ArcadeHexagon::ArcadeHexagon(bool select) : Arcade(ach::ArcadeGame::agHexagon, select)
{
	center = new sf::CircleShape(ARCADE_HEXAGON_RADIUS, 6);
	player = new sf::CircleShape(2);
	shape  = new sf::ConvexShape(4);

	out    = new sf::RenderTexture();
	screen = new sf::Sprite();

	cntr   = sf::Vector2f(ARCADE_BORDER_WIDTH / 2, ARCADE_BORDER_HEIGHT / 2);

	out->create(ARCADE_BORDER_WIDTH, ARCADE_BORDER_HEIGHT);
	out->setRepeated(false);
	out->setActive(true);
	out->setSmooth(false);

	screen->setTexture(out->getTexture());
	screen->setPosition(offset);

	player->setOrigin(2, 2);
	player->setFillColor(sf::Color::Green);

	center->setOrigin  (ARCADE_HEXAGON_RADIUS   , ARCADE_HEXAGON_RADIUS   );
	center->setPosition(cntr);
	center->setFillColor(sf::Color::Transparent);
	center->setOutlineColor(sf::Color::White);
	center->setOutlineThickness(1);

	border->setOutlineColor(sf::Color::Transparent);

	line[0].color = sf::Color(100, 100, 100);
	line[1].color = sf::Color(100, 100, 100);

	shape->setFillColor(sf::Color::White);

	ticker.set(1.0f);
}



/***********************************************************************
     * ArcadeHexagon
     * destructor

***********************************************************************/
ach::ArcadeHexagon::~ArcadeHexagon()
{
	delete out;
	delete screen;

	delete player;
	delete center;
	delete shape;
}



/***********************************************************************
     * ArcadeHexagon
     * prepare

***********************************************************************/
void ach::ArcadeHexagon::prepare()
{
	rot   = 0.0f;
	speed = 1;
	pos   = MATH_PI / 3.0f;

	fill();
	rotate();
}



/***********************************************************************
     * ArcadeHexagon
     * process

***********************************************************************/
void ach::ArcadeHexagon::process()
{
	score.add(ticker.update(true));

	if (!rotor.update(true))
		rotate();

	if (collide(pos))
		gameover();

	rot += speed * tm->get(true);

	for (int i = 0; i < 6; i++)
		sectors[i] -= ARCADE_HEXAGON_SPEED * tm->get(true);

	if (!check())
		fill();
}



/***********************************************************************
     * ArcadeHexagon
     * draw

***********************************************************************/
void ach::ArcadeHexagon::draw()
{
	center->setRotation((rot + MATH_PI / 6.0f) * MATH_DEG);
	player->setPosition(convert(pos, ARCADE_HEXAGON_OFFSET));

	out->clear(sf::Color::Transparent);
	out->draw(*center);
	out->draw(*player);

	for (int i = 0; i < 6; i++)
	{
		renderLine(i);
		renderShape(i, sectors[i]);
	}

	out->display();
	tex->draw(*screen);
}



/***********************************************************************
     * ArcadeHexagon
     * handle

***********************************************************************/
void ach::ArcadeHexagon::handle()
{
	if (ctrl->keys[ach::ControlAction::caLeft ].state) move(-1);
	if (ctrl->keys[ach::ControlAction::caRight].state) move( 1);
}



/***********************************************************************
     * ArcadeHexagon
     * fill

***********************************************************************/
void ach::ArcadeHexagon::fill()
{
	std::vector<int> list;
	int k;

	for (int i = 0; i < 6; i++)
		list.push_back(i);

	random_shuffle(&list);

	k = (rand() % 5) + 1;

	for (int i = 0; i < 6; i++)
		sectors[list[i]] = ARCADE_HEXAGON_MIN + ARCADE_HEXAGON_STEP * (i / k);
}



/***********************************************************************
     * ArcadeHexagon
     * rotate

***********************************************************************/
void ach::ArcadeHexagon::rotate()
{
	speed = -math_sign(speed) * random_float(0.5f, 1.0f) * MATH_PI;

	rotor.set(fabs(2 * MATH_PI / speed));
}



/***********************************************************************
     * ArcadeHexagon
     * move

***********************************************************************/
void ach::ArcadeHexagon::move(int d)
{
	if (!collide(pos + tm->get(true) * d * ARCADE_HEXAGON_MOVE))
		pos += tm->get(true) * d * ARCADE_HEXAGON_MOVE;

	if (pos <  0.0f)
		pos += 2.0f * MATH_PI;

	if (pos >  2.0f * MATH_PI)
		pos -= 2.0f * MATH_PI;
}



/***********************************************************************
     * ArcadeHexagon
     * check

***********************************************************************/
bool ach::ArcadeHexagon::check()
{
	for (int i = 0; i < 6; i++)
		if (sectors[i] > ARCADE_HEXAGON_RADIUS - ARCADE_HEXAGON_THICK)
			return true;

	return false;
}



/***********************************************************************
     * ArcadeHexagon
     * collide

***********************************************************************/
bool ach::ArcadeHexagon::collide(float angle)
{
	if (angle <  0.0f)
		angle += 2.0f * MATH_PI;

	if (angle >  2.0f * MATH_PI)
		angle -= 2.0f * MATH_PI;

	int section   = floor(angle / (MATH_PI / 3.0f));

	float loBound = sectors[section];
	float hiBound = sectors[section] + ARCADE_HEXAGON_THICK;

	if (ARCADE_HEXAGON_OFFSET > loBound && ARCADE_HEXAGON_OFFSET < hiBound)
		return true;

	return false;
}



/***********************************************************************
     * ArcadeHexagon
     * renderLine

***********************************************************************/
void ach::ArcadeHexagon::renderLine(int i)
{
	line[0].position = convert(i, ARCADE_HEXAGON_RADIUS);
	line[1].position = convert(i, ARCADE_BORDER_HEIGHT );

	out->draw(line, 2, sf::Lines);
}



/***********************************************************************
     * ArcadeHexagon
     * renderShape

***********************************************************************/
void ach::ArcadeHexagon::renderShape(int i, float dist)
{
	shape->setPoint(0, convert(i    , dist                       ));
	shape->setPoint(1, convert(i    , dist + ARCADE_HEXAGON_THICK));
	shape->setPoint(2, convert(i + 1, dist + ARCADE_HEXAGON_THICK));
	shape->setPoint(3, convert(i + 1, dist                       ));

	out->draw(*shape);
}



/***********************************************************************
     * ArcadeHexagon
     * convert

***********************************************************************/
sf::Vector2f ach::ArcadeHexagon::convert(int i, float radius)
{
	return convert(2.0f * MATH_PI * i / 6.0f, (radius < ARCADE_HEXAGON_RADIUS) ? ARCADE_HEXAGON_RADIUS : radius);
}



/***********************************************************************
     * ArcadeHexagon
     * convert

***********************************************************************/
sf::Vector2f ach::ArcadeHexagon::convert(float angle, float radius)
{
	return sf::Vector2f(cos(rot + angle), sin(rot + angle)) * radius + cntr;
}
