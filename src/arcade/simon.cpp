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
}



/***********************************************************************
     * ArcadeSimon
     * process

***********************************************************************/
void ach::ArcadeSimon::process()
{
}



/***********************************************************************
     * ArcadeSimon
     * draw

***********************************************************************/
void ach::ArcadeSimon::draw()
{
}



/***********************************************************************
     * ArcadeSimon
     * handle

***********************************************************************/
void ach::ArcadeSimon::handle()
{
}
