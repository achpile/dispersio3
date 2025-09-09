#include "meta/headers.hpp"


/***********************************************************************
     * ArcadeSimon
     * constructor

***********************************************************************/
ach::ArcadeSimon::ArcadeSimon(bool select) : Arcade(ach::ArcadeGame::Simon, select)
{
	shapeUp    = new sf::ConvexShape(4);
	shapeDown  = new sf::ConvexShape(4);
	shapeLeft  = new sf::ConvexShape(4);
	shapeRight = new sf::ConvexShape(4);

	shapeUp->setPoint(0, sf::Vector2f( 45,  10));
	shapeUp->setPoint(1, sf::Vector2f(205,  10));
	shapeUp->setPoint(2, sf::Vector2f(165,  50));
	shapeUp->setPoint(3, sf::Vector2f( 85,  50));

	shapeDown->setPoint(0, sf::Vector2f( 45, 190));
	shapeDown->setPoint(1, sf::Vector2f(205, 190));
	shapeDown->setPoint(2, sf::Vector2f(165, 150));
	shapeDown->setPoint(3, sf::Vector2f( 85, 150));

	shapeLeft->setPoint(0, sf::Vector2f( 35,  20));
	shapeLeft->setPoint(1, sf::Vector2f( 75,  60));
	shapeLeft->setPoint(2, sf::Vector2f( 75, 140));
	shapeLeft->setPoint(3, sf::Vector2f( 35, 180));

	shapeRight->setPoint(0, sf::Vector2f(215,  20));
	shapeRight->setPoint(1, sf::Vector2f(175,  60));
	shapeRight->setPoint(2, sf::Vector2f(175, 140));
	shapeRight->setPoint(3, sf::Vector2f(215, 180));

	shapeUp->setOutlineColor(sf::Color::White);
	shapeDown->setOutlineColor(sf::Color::White);
	shapeLeft->setOutlineColor(sf::Color::White);
	shapeRight->setOutlineColor(sf::Color::White);

	shapeUp->setPosition(offset);
	shapeDown->setPosition(offset);
	shapeLeft->setPosition(offset);
	shapeRight->setPosition(offset);

	sndUp    = db->getSound(json_object_get_branch_string(dm->data, "Meta.Arcade.Simon.Up"     ))->snd;
	sndDown  = db->getSound(json_object_get_branch_string(dm->data, "Meta.Arcade.Simon.Down"   ))->snd;
	sndLeft  = db->getSound(json_object_get_branch_string(dm->data, "Meta.Arcade.Simon.Left"   ))->snd;
	sndRight = db->getSound(json_object_get_branch_string(dm->data, "Meta.Arcade.Simon.Right"  ))->snd;
	sndCorr  = db->getSound(json_object_get_branch_string(dm->data, "Meta.Arcade.Simon.Correct"))->snd;

	ticker.set(0.33f);
}



/***********************************************************************
     * ArcadeSimon
     * destructor

***********************************************************************/
ach::ArcadeSimon::~ArcadeSimon()
{
	delete shapeUp;
	delete shapeDown;
	delete shapeLeft;
	delete shapeRight;
}



/***********************************************************************
     * ArcadeSimon
     * prepare

***********************************************************************/
void ach::ArcadeSimon::prepare()
{
	for (int i = 0; i < ARCADE_SIMON_SIZE; i++)
		seq[i] = (ach::Direction)(rand() % ach::Direction::dCount);

	pos   = 0;
	len   = 1;
	stage = ach::ArcadeSimonStage::Demo;

	clear(false);
}



/***********************************************************************
     * ArcadeSimon
     * process

***********************************************************************/
void ach::ArcadeSimon::process()
{
	if (!ticker.update(true))
		tick();
}



/***********************************************************************
     * ArcadeSimon
     * draw

***********************************************************************/
void ach::ArcadeSimon::draw()
{
	shape(shapeUp   , sf::Color(0, 1, 0), buttons[ach::Direction::dUp   ] ? 255 : 100);
	shape(shapeDown , sf::Color(0, 0, 1), buttons[ach::Direction::dDown ] ? 255 : 100);
	shape(shapeLeft , sf::Color(1, 1, 0), buttons[ach::Direction::dLeft ] ? 255 : 100);
	shape(shapeRight, sf::Color(1, 0, 0), buttons[ach::Direction::dRight] ? 255 : 100);
}



/***********************************************************************
     * ArcadeSimon
     * handle

***********************************************************************/
void ach::ArcadeSimon::handle()
{
	if (stage != ach::ArcadeSimonStage::Input)
		return;

	if (ctrl->keys[ach::ControlAction::caUp   ].pressed) press(ach::Direction::dUp   );
	if (ctrl->keys[ach::ControlAction::caDown ].pressed) press(ach::Direction::dDown );
	if (ctrl->keys[ach::ControlAction::caLeft ].pressed) press(ach::Direction::dLeft );
	if (ctrl->keys[ach::ControlAction::caRight].pressed) press(ach::Direction::dRight);
}



/***********************************************************************
     * ArcadeSimon
     * tick

***********************************************************************/
void ach::ArcadeSimon::tick()
{
	switch (stage)
	{
		case ach::ArcadeSimonStage::Demo:
			stage = ach::ArcadeSimonStage::Pause;

			ticker.set(0.1f);
			clear(false);
		break;


		case ach::ArcadeSimonStage::Pause:
			stage = ach::ArcadeSimonStage::Demo;
			press(seq[pos]);
		break;


		case ach::ArcadeSimonStage::Input:
			clear(false);
		break;


		case ach::ArcadeSimonStage::Correct:
			stage = ach::ArcadeSimonStage::Pause;
			pos   = 0;

			len++;
			ticker.set(0.66f);

			clear(len > ARCADE_SIMON_SIZE);

			if (len > ARCADE_SIMON_SIZE)
			{
				stage = ach::ArcadeSimonStage::Create;

				sm->play(sndCorr);
			}
		break;


		case ach::ArcadeSimonStage::Create:
			prepare();
		break;
	}
}



/***********************************************************************
     * ArcadeSimon
     * clear

***********************************************************************/
void ach::ArcadeSimon::clear(bool value)
{
	buttons[ach::Direction::dUp   ] = value;
	buttons[ach::Direction::dDown ] = value;
	buttons[ach::Direction::dLeft ] = value;
	buttons[ach::Direction::dRight] = value;
}



/***********************************************************************
     * ArcadeSimon
     * press

***********************************************************************/
void ach::ArcadeSimon::press(ach::Direction dir)
{
	if (dir != seq[pos])
	{
		gameover();
		return;
	}

	clear(false);
	buttons[dir] = true;

	switch (dir)
	{
		case ach::Direction::dUp   : sm->play(sndUp   ); break;
		case ach::Direction::dDown : sm->play(sndDown ); break;
		case ach::Direction::dLeft : sm->play(sndLeft ); break;
		case ach::Direction::dRight: sm->play(sndRight); break;

		case ach::Direction::dCount: break;
	}

	ticker.set(0.33f);

	pos++;

	switch (stage)
	{
		case ach::ArcadeSimonStage::Demo:
			if (pos == len)
			{
				pos   = 0;
				stage = ach::ArcadeSimonStage::Input;
			}
		break;


		case ach::ArcadeSimonStage::Input:
			score++;

			if (pos == len)
			{
				pos   = 0;
				stage = ach::ArcadeSimonStage::Correct;
			}
		break;


		case ach::ArcadeSimonStage::Create :
		case ach::ArcadeSimonStage::Pause  :
		case ach::ArcadeSimonStage::Correct:
		break;
	}
}



/***********************************************************************
     * ArcadeSimon
     * shape

***********************************************************************/
void ach::ArcadeSimon::shape(sf::ConvexShape *shape, sf::Color c, int value)
{
	shape->setFillColor(sf::Color(c.r * value, c.g * value, c.b * value));
	shape->setOutlineThickness((value == 255) ? 1.0f : 0.0f);

	tex->draw(*shape);
}
