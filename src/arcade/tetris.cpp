#include "meta/headers.hpp"


/***********************************************************************
     * ArcadeTetris
     * constructor

***********************************************************************/
ach::ArcadeTetris::ArcadeTetris(bool select) : Arcade(ach::ArcadeGame::Tetris, select)
{
	square = new sf::RectangleShape(sf::Vector2f(ARCADE_SQUARE - 1, ARCADE_SQUARE - 1));

	line   = db->getSound(json_object_get_branch_string(dm->data, "Meta.Arcade.Tetris.Line"))->snd;
	lnd    = db->getSound(json_object_get_branch_string(dm->data, "Meta.Arcade.Tetris.Land"))->snd;

	border->setPosition(sf::Vector2f(ARCADE_TETRIS_OFFSET - 1, ARCADE_OFFSET_Y      - 1));
	border->setSize    (sf::Vector2f(ARCADE_TETRIS_WIDTH  + 1, ARCADE_BORDER_HEIGHT + 1));

	ticker.set(0.33f);
}



/***********************************************************************
     * ArcadeTetris
     * destructor

***********************************************************************/
ach::ArcadeTetris::~ArcadeTetris()
{
	delete square;
}



/***********************************************************************
     * ArcadeTetris
     * prepare

***********************************************************************/
void ach::ArcadeTetris::prepare()
{
	for (int i = 0; i < ARCADE_TETRIS_X; i++)
		for (int j = 0; j < ARCADE_TETRIS_Y; j++)
			field[i][j] = false;

	gen();
	next();
	gen();
}



/***********************************************************************
     * ArcadeTetris
     * process

***********************************************************************/
void ach::ArcadeTetris::process()
{
	if (!ticker.update(true))
		tick();
}



/***********************************************************************
     * ArcadeTetris
     * draw

***********************************************************************/
void ach::ArcadeTetris::draw()
{
	for (int i = 0; i < ARCADE_TETRIS_X; i++)
		for (int j = 0; j < ARCADE_TETRIS_Y; j++)
			if(field[i][j])
				renderSquare(i, j, sf::Color::White);

	for (int i = 0; i < 4; i++)
		renderSquare(figure[i].x, figure[i].y, sf::Color::Green);

	for (int i = 0; i < 4; i++)
		renderSquare(upcome[i].x + 9, upcome[i].y + 4, sf::Color::White);
}



/***********************************************************************
     * ArcadeTetris
     * handle

***********************************************************************/
void ach::ArcadeTetris::handle()
{
	if (ctrl->keys[ach::ControlAction::caLeft ].pressed) move(-1, 0);
	if (ctrl->keys[ach::ControlAction::caRight].pressed) move( 1, 0);
	if (ctrl->keys[ach::ControlAction::caDown ].pressed) tick();
	if (ctrl->keys[ach::ControlAction::caJump ].pressed) rotate();

	ticker.timer = (ctrl->keys[ach::ControlAction::caDown ].state) ? 0.05f : 0.33f;
}



/***********************************************************************
     * ArcadeTetris
     * gen

***********************************************************************/
void ach::ArcadeTetris::gen()
{
	switch (rand() % 7)
	{
		case 0:
			upcome[0] = sf::Vector2i(4,0);
			upcome[1] = sf::Vector2i(4,1);
			upcome[2] = sf::Vector2i(5,0);
			upcome[3] = sf::Vector2i(5,1);
		break;

		case 1:
			upcome[0] = sf::Vector2i(4,0);
			upcome[1] = sf::Vector2i(5,0);
			upcome[2] = sf::Vector2i(3,1);
			upcome[3] = sf::Vector2i(4,1);
		break;

		case 2:
			upcome[0] = sf::Vector2i(4,0);
			upcome[1] = sf::Vector2i(5,0);
			upcome[2] = sf::Vector2i(5,1);
			upcome[3] = sf::Vector2i(6,1);
		break;

		case 3:
			upcome[0] = sf::Vector2i(3,0);
			upcome[1] = sf::Vector2i(4,0);
			upcome[2] = sf::Vector2i(5,0);
			upcome[3] = sf::Vector2i(6,0);
		break;

		case 4:
			upcome[0] = sf::Vector2i(4,0);
			upcome[1] = sf::Vector2i(3,1);
			upcome[2] = sf::Vector2i(4,1);
			upcome[3] = sf::Vector2i(5,1);
		break;

		case 5:
			upcome[0] = sf::Vector2i(3,0);
			upcome[1] = sf::Vector2i(3,1);
			upcome[2] = sf::Vector2i(4,1);
			upcome[3] = sf::Vector2i(5,1);
		break;

		case 6:
			upcome[0] = sf::Vector2i(5,0);
			upcome[1] = sf::Vector2i(3,1);
			upcome[2] = sf::Vector2i(4,1);
			upcome[3] = sf::Vector2i(5,1);
		break;
	}
}



/***********************************************************************
     * ArcadeTetris
     * next

***********************************************************************/
void ach::ArcadeTetris::next()
{
	for (int i = 0; i < 4; i++)
		figure[i] = upcome[i];

	if (!check())
		gameover();
}



/***********************************************************************
     * ArcadeTetris
     * tick

***********************************************************************/
void ach::ArcadeTetris::tick()
{
	ticker.reset();

	copy();
	move(0, 1);

	if (!check())
	{
		undo();
		land();
		lines();
		next();
		gen();
	}
}



/***********************************************************************
     * ArcadeTetris
     * land

***********************************************************************/
void ach::ArcadeTetris::land()
{
	for (int i = 0; i < 4; i++)
		field[figure[i].x][figure[i].y] = true;

	sm->play(lnd);
}



/***********************************************************************
     * ArcadeTetris
     * lines

***********************************************************************/
void ach::ArcadeTetris::lines()
{
	bool removed = false;
	int  count = 0;
	int  blocks;
	int  k = ARCADE_TETRIS_Y - 1;

	for (int i = ARCADE_TETRIS_Y - 1; i >= 0; i--)
	{
		blocks = 0;

		for (int j = 0; j < ARCADE_TETRIS_X; j++)
		{
			if (field[j][i])
				blocks++;

			field[j][k] = field[j][i];
		}

		if (blocks < ARCADE_TETRIS_X)
		{
			k--;
		}
		else
		{
			removed = true;
			count++;
		}
	}


	for (; k >= 0; k--)
		for (int j = 0; j < ARCADE_TETRIS_X; j++)
			field[j][k] = false;


	if (removed)
	{
		for (int i = 1; i <= count; i++)
			score += i;

		sm->play(line);
	}
}



/***********************************************************************
     * ArcadeTetris
     * copy

***********************************************************************/
void ach::ArcadeTetris::copy()
{
	for (int i = 0; i < 4; i++)
		backup[i] = figure[i];
}



/***********************************************************************
     * ArcadeTetris
     * undo

***********************************************************************/
void ach::ArcadeTetris::undo()
{
	for (int i = 0; i < 4; i++)
		figure[i] = backup[i];
}



/***********************************************************************
     * ArcadeTetris
     * check

***********************************************************************/
bool ach::ArcadeTetris::check()
{
	for (int i = 0; i < 4; i++)
	{
		if (figure[i].x < 0)
			return false;

		if (figure[i].x >= ARCADE_TETRIS_X)
			return false;

		if (figure[i].y >= ARCADE_TETRIS_Y)
			return false;

		if (field[figure[i].x][figure[i].y])
			return false;
	}

	return true;
}



/***********************************************************************
     * ArcadeTetris
     * rotate

***********************************************************************/
void ach::ArcadeTetris::rotate()
{
	copy();

	sf::Vector2i a = figure[0];
	sf::Vector2i c;
	sf::Vector2i m;

	for (int i = 1; i < 4; i++)
	{
		if (a.x > figure[i].x) a.x = figure[i].x;
		if (a.y > figure[i].y) a.y = figure[i].y;
	}

	for (int i = 0; i < 4; i++)
	{
		m.x = figure[i].y - c.y;
		m.y = figure[i].x - c.x;

		figure[i].x = c.x - m.x;
		figure[i].y = c.y + m.y;
	}

	m = figure[0] - a;

	for (int i = 1; i < 4; i++)
	{
		if (m.x > figure[i].x - a.x) m.x = figure[i].x - a.x;
		if (m.y > figure[i].y - a.y) m.y = figure[i].y - a.y;
	}

	for (int i = 0; i < 4; i++)
		figure[i] -= m;

	if (!check())
		undo();
}



/***********************************************************************
     * ArcadeTetris
     * move

***********************************************************************/
void ach::ArcadeTetris::move(int dx, int dy)
{
	copy();

	for (int i = 0; i < 4; i++)
		figure[i] += sf::Vector2i(dx, dy);

	if (!dy && !check())
		undo();
}



/***********************************************************************
     * ArcadeTetris
     * renderSquare

***********************************************************************/
void ach::ArcadeTetris::renderSquare(int x, int y, sf::Color color)
{
	square->setFillColor(color);
	square->setPosition(ARCADE_TETRIS_OFFSET + ARCADE_SQUARE * x,
	                    ARCADE_OFFSET_Y      + ARCADE_SQUARE * y);

	tex->draw(*square);
}
