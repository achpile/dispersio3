#include "meta/headers.hpp"


/***********************************************************************
     * Player
     * constructor

***********************************************************************/
ach::Player::Player()
{
	character = new ach::Character(sf::Vector2f(16.0f, 16.0f));

	legs = new ach::Model(db->getModel("PlayerLegs"));
	body = new ach::Model(db->getModel("PlayerBody"));

	character->models.push_back(legs);
	character->models.push_back(body);

	character->speed   = 100.0f;
	character->jumping = 300.0f;
}



/***********************************************************************
     * Player
     * destructor

***********************************************************************/
ach::Player::~Player()
{
}



/***********************************************************************
     * Player
     * update

***********************************************************************/
void ach::Player::update()
{
	character->update();
}



/***********************************************************************
     * Player
     * render

***********************************************************************/
void ach::Player::render()
{
	character->render();
}



/***********************************************************************
     * Player
     * controls

***********************************************************************/
void ach::Player::controls()
{
	if (character->dead)
		return;

	character->phys.vel.x  = 0.0f;
	character->phys.moving = false;

	if (ctrl->keys[ach::ControlAction::caLeft ].state) move(-1);
	if (ctrl->keys[ach::ControlAction::caRight].state) move( 1);

	character->phys.jumpdown = ctrl->keys[ach::ControlAction::caJump].state &&
	                           ctrl->keys[ach::ControlAction::caDown].state;

	if (ctrl->keys[ach::ControlAction::caJump ].pressed) character->jump();
}



/***********************************************************************
     * Player
     * reset

***********************************************************************/
void ach::Player::reset()
{
	legs->setAnimation("Idle");
	body->setAnimation("Front");

	dir = sf::Vector2i(1, 0);

	character->reset();
}



/***********************************************************************
     * Player
     * respawn

***********************************************************************/
void ach::Player::respawn(sf::Vector2f spawn)
{
	character->phys.pos = spawn;

	reset();
}



/***********************************************************************
     * Player
     * move

***********************************************************************/
void ach::Player::move(int d)
{
	character->move(d);
}
