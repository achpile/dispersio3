#include "meta/headers.hpp"


/***********************************************************************
     * ArcadeSnake
     * constructor

***********************************************************************/
ach::ArcadeSnake::ArcadeSnake(bool select) : Arcade(ach::ArcadeGame::Snake, select)
{
	eat   = db->getSound(json_object_get_branch_string(dm->data, "Meta.Arcade.Snake.Eat"  ))->snd;
	clear = db->getSound(json_object_get_branch_string(dm->data, "Meta.Arcade.Snake.Clear"))->snd;

	ticker.set(0.1f);
}



/***********************************************************************
     * ArcadeSnake
     * destructor

***********************************************************************/
ach::ArcadeSnake::~ArcadeSnake()
{
}



/***********************************************************************
     * ArcadeSnake
     * prepare

***********************************************************************/
void ach::ArcadeSnake::prepare()
{
	pulse.set(0.25f);

	dir  = ach::Direction::dRight;
	next = ach::Direction::dRight;

	snake.clear();
	snake.push_back(sf::Vector2i(3, ARCADE_SNAKE_Y / 2));
	snake.push_back(sf::Vector2i(2, ARCADE_SNAKE_Y / 2));
	snake.push_back(sf::Vector2i(1, ARCADE_SNAKE_Y / 2));

	gen();
}



/***********************************************************************
     * ArcadeSnake
     * process

***********************************************************************/
void ach::ArcadeSnake::process()
{
	if (!ticker.update(true))
	{
		tick();
		ticker.reset();
	}

	pulse.update(true);
}



/***********************************************************************
     * ArcadeSnake
     * draw

***********************************************************************/
void ach::ArcadeSnake::draw()
{
	renderSquare(snake[0], sf::Color::Green);

	for (unsigned int i = 1; i < snake.size(); i++)
		renderSquare(snake[i], sf::Color::White);

	if (pulse.active)
		renderSquare(fruit, sf::Color::Red);
}



/***********************************************************************
     * ArcadeSnake
     * handle

***********************************************************************/
void ach::ArcadeSnake::handle()
{
	if (ctrl->keys[ach::ControlAction::caLeft ].pressed) turn(ach::Direction::dLeft );
	if (ctrl->keys[ach::ControlAction::caRight].pressed) turn(ach::Direction::dRight);
	if (ctrl->keys[ach::ControlAction::caUp   ].pressed) turn(ach::Direction::dUp   );
	if (ctrl->keys[ach::ControlAction::caDown ].pressed) turn(ach::Direction::dDown );
}



/***********************************************************************
     * ArcadeSnake
     * gen

***********************************************************************/
void ach::ArcadeSnake::gen()
{
	bool field[ARCADE_SNAKE_X][ARCADE_SNAKE_Y];

	for (int x = 0; x < ARCADE_SNAKE_X; x++)
		for (int y = 0; y < ARCADE_SNAKE_Y; y++)
			field[x][y] = true;

	list_foreach(snake)
		field[snake[i].x][snake[i].y] = false;


	std::vector<sf::Vector2i> available;

	for (int x = 0; x < ARCADE_SNAKE_X; x++)
		for (int y = 0; y < ARCADE_SNAKE_Y; y++)
			if (field[x][y])
				available.push_back(sf::Vector2i(x, y));


	if (!available.size())
	{
		sm->play(clear);
		prepare();
		return;
	}

	fruit = available[rand() % available.size()];
}



/***********************************************************************
     * ArcadeSnake
     * tick

***********************************************************************/
void ach::ArcadeSnake::tick()
{
	if (!move())
		gameover();
}



/***********************************************************************
     * ArcadeSnake
     * move

***********************************************************************/
bool ach::ArcadeSnake::move()
{
	dir = next;

	sf::Vector2i step = snake[0] + dir_vector_i(dir);

	if (step.x < 0) return false;
	if (step.y < 0) return false;

	if (step.x >= ARCADE_SNAKE_X) return false;
	if (step.y >= ARCADE_SNAKE_Y) return false;


	for (unsigned int i = 0; i < snake.size(); i++)
		if (step == snake[i])
			return false;


	if (step == fruit)
	{
		snake.push_back(sf::Vector2i(0, 0));

		score++;

		sm->play(eat);
		gen();
	}


	for (unsigned int i = snake.size() - 1; i > 0; i--)
		snake[i] = snake[i-1];

	snake[0] = step;

	return true;
}



/***********************************************************************
     * ArcadeSnake
     * turn

***********************************************************************/
void ach::ArcadeSnake::turn(ach::Direction _dir)
{
	if (dir_orient(dir) == dir_orient(_dir))
		return;

	next = _dir;
}
