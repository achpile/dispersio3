#include "meta/headers.hpp"


/***********************************************************************
     * Player
     * constructor

***********************************************************************/
ach::Player::Player(ach::ProcessWorld *world)
{
	character = new ach::Character(world, db->getCharacter("Player"));

	legs = new ach::Model(db->getModel("PlayerLegs"));
	body = new ach::Model(db->getModel("PlayerBody"));

	character->models.push_back(legs);
	character->models.push_back(body);
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
	animate();
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

	character->aim = sf::Vector2f(0.0f, 0.0f);

	dir.y = 0;

	character->phys.vel.x  = 0.0f;
	character->phys.moving = false;

	if (ctrl->keys[ach::ControlAction::caLeft ].state) move(-1);
	if (ctrl->keys[ach::ControlAction::caRight].state) move( 1);

	character->phys.jumpdown = ctrl->keys[ach::ControlAction::caJump].state &&
	                           ctrl->keys[ach::ControlAction::caDown].state;

	if (ctrl->keys[ach::ControlAction::caJump ].pressed) character->jump();
	if (ctrl->keys[ach::ControlAction::caShot ].state  ) character->shot();

	if (ctrl->keys[ach::ControlAction::caUp  ].state) dir.y = -1;
	if (ctrl->keys[ach::ControlAction::caDown].state) dir.y =  1;


	character->aim = sf::Vector2f(dir);

	if (dir.y == -1 && !character->phys.moving)
		character->aim.x = 0.0f;
}



/***********************************************************************
     * Player
     * animate

***********************************************************************/
void ach::Player::animate()
{
	if (character->phys.grounded)
	{
		if (character->phys.moving)
			legs->setAnimation("Walk");
		else
			legs->setAnimation("Idle");
	}
	else
	{
		if (character->phys.vel.y > 0.0f)
			legs->setAnimation("Fall");
		else
			legs->setAnimation("Jump");
	}


	if (dir.y == 0)
	{
		body->setAnimation("Front");
	}
	else if (dir.y == 1)
	{
		body->setAnimation("DiagonalDown");
	}
	else
	{
		if (character->phys.moving)
			body->setAnimation("DiagonalUp");
		else
			body->setAnimation("Up");
	}


	legs->scale.x = dir.x;
	body->scale.x = dir.x;
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
	dir.x = d;

	character->move(d);
}
