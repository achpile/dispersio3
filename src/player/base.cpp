#include "meta/headers.hpp"


/***********************************************************************
     * Player
     * constructor

***********************************************************************/
ach::Player::Player()
{
	legs = new ach::Model(db->getModel("PlayerLegs"));
	body = new ach::Model(db->getModel("PlayerBody"));

	legs->setAnimation("Idle");
	body->setAnimation("Front");
}



/***********************************************************************
     * Player
     * destructor

***********************************************************************/
ach::Player::~Player()
{
	delete legs;
	delete body;
}



/***********************************************************************
     * Player
     * update

***********************************************************************/
void ach::Player::update()
{
	legs->update();
	body->update();
}



/***********************************************************************
     * Player
     * render

***********************************************************************/
void ach::Player::render()
{
	legs->render(sf::Vector2f(13*16+8, 6*16+8));
	body->render(sf::Vector2f(13*16+8, 6*16+8));
}
