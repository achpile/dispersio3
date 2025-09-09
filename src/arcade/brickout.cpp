#include "meta/headers.hpp"


/***********************************************************************
     * ArcadeBrickOut
     * constructor

***********************************************************************/
ach::ArcadeBrickOut::ArcadeBrickOut(bool select) : Arcade(ach::ArcadeGame::BrickOut, select)
{
	pad    = new sf::RectangleShape(sf::Vector2f(ARCADE_BRICKOUT_P - 1, ARCADE_BRICKOUT_H - 1));
	tile   = new sf::RectangleShape(sf::Vector2f(ARCADE_BRICKOUT_W - 1, ARCADE_BRICKOUT_H - 1));
	square = new sf::RectangleShape(sf::Vector2f(ARCADE_SQUARE     - 1, ARCADE_SQUARE     - 1));

	pad->setFillColor   (sf::Color::Green);
	tile->setFillColor  (sf::Color::White);
	square->setFillColor(sf::Color::Red  );

	wall  = db->getSound(json_object_get_branch_string(dm->data, "Meta.Arcade.BrickOut.Wall" ))->snd;
	hit   = db->getSound(json_object_get_branch_string(dm->data, "Meta.Arcade.BrickOut.Tile" ))->snd;
	clear = db->getSound(json_object_get_branch_string(dm->data, "Meta.Arcade.BrickOut.Clear"))->snd;
}



/***********************************************************************
     * ArcadeBrickOut
     * destructor

***********************************************************************/
ach::ArcadeBrickOut::~ArcadeBrickOut()
{
	delete pad;
	delete tile;
	delete square;
}



/***********************************************************************
     * ArcadeBrickOut
     * prepare

***********************************************************************/
void ach::ArcadeBrickOut::prepare()
{
	lives = 3;

	fill();
}



/***********************************************************************
     * ArcadeBrickOut
     * process

***********************************************************************/
void ach::ArcadeBrickOut::process()
{
	if (glue)
	{
		pos.x = x + (ARCADE_BRICKOUT_P - ARCADE_BRICKOUT_H) / 2.0f;
		pos.y = ARCADE_BORDER_HEIGHT - ARCADE_BRICKOUT_H * 2.0f;

		return;
	}

	pos += vel * tm->get(true);

	if (!check())
		die();

	finish();
}



/***********************************************************************
     * ArcadeBrickOut
     * draw

***********************************************************************/
void ach::ArcadeBrickOut::draw()
{
	renderPad();
	renderLives();
	renderTiles();
	renderSquare();
}



/***********************************************************************
     * ArcadeBrickOut
     * handle

***********************************************************************/
void ach::ArcadeBrickOut::handle()
{
	if (ctrl->keys[ach::ControlAction::caLeft ].state  ) move(-1);
	if (ctrl->keys[ach::ControlAction::caRight].state  ) move( 1);
	if (ctrl->keys[ach::ControlAction::caJump ].pressed) shot();
}



/***********************************************************************
     * ArcadeBrickOut
     * fill

***********************************************************************/
void ach::ArcadeBrickOut::fill()
{
	x    = (ARCADE_BORDER_WIDTH - ARCADE_BRICKOUT_P) / 2.0f;
	glue = true;

	for (int i = 0; i < ARCADE_BRICKOUT_X; i++)
		for (int j = 0; j < ARCADE_BRICKOUT_Y; j++)
			tiles[i][j] = true;
}



/***********************************************************************
     * ArcadeBrickOut
     * move

***********************************************************************/
void ach::ArcadeBrickOut::move(int d)
{
	x += d * ARCADE_BRICKOUT_S * tm->get(true);

	if (x < 0.0f)
		x = 0.0f;

	if (x > ARCADE_BORDER_WIDTH - ARCADE_BRICKOUT_P)
		x = ARCADE_BORDER_WIDTH - ARCADE_BRICKOUT_P;
}



/***********************************************************************
     * ArcadeBrickOut
     * shot

***********************************************************************/
void ach::ArcadeBrickOut::shot()
{
	if (!glue)
		return;

	glue  =  false;
	vel.x =  ARCADE_BRICKOUT_S * cos(MATH_PI / 4);
	vel.y = -ARCADE_BRICKOUT_S * sin(MATH_PI / 4);
}



/***********************************************************************
     * ArcadeBrickOut
     * die

***********************************************************************/
void ach::ArcadeBrickOut::die()
{
	glue = true;

	lives--;

	if (lives == 0) gameover();
	else            sm->play(over);
}



/***********************************************************************
     * ArcadeBrickOut
     * finish

***********************************************************************/
void ach::ArcadeBrickOut::finish()
{
	for (int i = 0; i < ARCADE_BRICKOUT_X; i++)
		for (int j = 0; j < ARCADE_BRICKOUT_Y; j++)
			if (tiles[i][j])
				return;

	sm->play(clear);
	fill();
}



/***********************************************************************
     * ArcadeBrickOut
     * check

***********************************************************************/
bool ach::ArcadeBrickOut::check()
{
	if (pos.x < 0                                       ) {vel.x = -vel.x; pos.x = 0.0f                                   ; sm->play(wall);}
	if (pos.x > ARCADE_BORDER_WIDTH  - ARCADE_BRICKOUT_H) {vel.x = -vel.x; pos.x = ARCADE_BORDER_WIDTH - ARCADE_BRICKOUT_H; sm->play(wall);}
	if (pos.y < 0                                       ) {vel.y = -vel.y; pos.y = 0.0f                                   ; sm->play(wall);}
	if (pos.y > ARCADE_BORDER_HEIGHT - ARCADE_BRICKOUT_H) return false;


	if (pos.y > ARCADE_BORDER_HEIGHT - ARCADE_BRICKOUT_H * 2.0f)
		collidePad();

	collideTiles();

	return true;
}



/***********************************************************************
     * ArcadeBrickOut
     * collidePad

***********************************************************************/
void ach::ArcadeBrickOut::collidePad()
{
	if ((pos.x < x - ARCADE_BRICKOUT_H) || (pos.x > x + ARCADE_BRICKOUT_P))
		return;

	float angle;

	angle  = 10.0f * ((x + ARCADE_BRICKOUT_P) - pos.x);
	angle /= (ARCADE_BRICKOUT_P + ARCADE_BRICKOUT_H);
	angle += 1.0f;
	angle *= (MATH_PI / 12.0f);

	pos.y =  ARCADE_BORDER_HEIGHT - ARCADE_BRICKOUT_H * 2.0f;
	vel.x =  ARCADE_BRICKOUT_S * cos(angle);
	vel.y = -ARCADE_BRICKOUT_S * sin(angle);

	sm->play(wall);
}



/***********************************************************************
     * ArcadeBrickOut
     * collideTiles

***********************************************************************/
void ach::ArcadeBrickOut::collideTiles()
{
	for (int i = 0; i < ARCADE_BRICKOUT_X; i++)
		for (int j = 0; j < ARCADE_BRICKOUT_Y; j++)
			collideTile(i, j);
}



/***********************************************************************
     * ArcadeBrickOut
     * collideTile

***********************************************************************/
void ach::ArcadeBrickOut::collideTile(int i, int j)
{
	if (!tiles[i][j])
		return;

	sf::FloatRect intersection;
	sf::FloatRect sqr;
	sf::FloatRect rect;

	sqr  = sf::FloatRect(pos.x                , pos.y                , ARCADE_SQUARE    , ARCADE_SQUARE    );
	rect = sf::FloatRect(i * ARCADE_BRICKOUT_W, j * ARCADE_BRICKOUT_H, ARCADE_BRICKOUT_W, ARCADE_BRICKOUT_H);

	if (!rect.intersects(sqr, intersection))
		return;

	if (fabs(intersection.width ) < 0.1f) return;
	if (fabs(intersection.height) < 0.1f) return;

	score++;
	sm->play(hit);

	if (fabs(intersection.width) > fabs(intersection.height))
	{
		vel.y = -vel.y;

		if (pos.y < rect.top) pos.y -= fabs(intersection.height);
		else                  pos.y += fabs(intersection.height);
	}
	else
	{
		vel.x = -vel.x;

		if (pos.x < rect.left) pos.y -= fabs(intersection.width);
		else                   pos.y += fabs(intersection.width);
	}

	tiles[i][j] = false;
}



/***********************************************************************
     * ArcadeBrickOut
     * renderPad

***********************************************************************/
void ach::ArcadeBrickOut::renderPad()
{
	pad->setPosition(sf::Vector2f(x, ARCADE_BORDER_HEIGHT - ARCADE_BRICKOUT_H) + offset);

	tex->draw(*pad);
}



/***********************************************************************
     * ArcadeBrickOut
     * renderLives

***********************************************************************/
void ach::ArcadeBrickOut::renderLives()
{
	for (int i = 0; i <= lives - 1; i++)
	{
		square->setPosition(sf::Vector2f(i * ARCADE_SQUARE * 1.5f, -ARCADE_SQUARE * 1.5f) + offset);
		tex->draw(*square);
	}
}



/***********************************************************************
     * ArcadeBrickOut
     * renderSquare

***********************************************************************/
void ach::ArcadeBrickOut::renderSquare()
{
	square->setPosition(pos + offset);

	tex->draw(*square);
}



/***********************************************************************
     * ArcadeBrickOut
     * renderTiles

***********************************************************************/
void ach::ArcadeBrickOut::renderTiles()
{
	for (int i = 0; i < ARCADE_BRICKOUT_X; i++)
		for (int j = 0; j < ARCADE_BRICKOUT_Y; j++)
			renderTile(i, j);
}



/***********************************************************************
     * ArcadeBrickOut
     * renderTile

***********************************************************************/
void ach::ArcadeBrickOut::renderTile(int i, int j)
{
	if (!tiles[i][j])
		return;

	tile->setPosition(sf::Vector2f(ARCADE_BRICKOUT_W * i, ARCADE_BRICKOUT_H * j) + offset);

	tex->draw(*tile);
}
