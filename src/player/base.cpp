#include "meta/headers.hpp"


/***********************************************************************
     * Player
     * constructor

***********************************************************************/
ach::Player::Player()
{
	phys.init(sf::Vector2f(16.0f, 16.0f));
	phys.pos = sf::Vector2f(13*16+8, 6*16+8);

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
	legs->render(phys.pos);
	body->render(phys.pos);
}
