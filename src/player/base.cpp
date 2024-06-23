#include "meta/headers.hpp"


/***********************************************************************
     * Player
     * constructor

***********************************************************************/
ach::Player::Player(ach::ProcessWorld *world)
{
	character = new ach::Character(world, db->getCharacter("Player"));
}



/***********************************************************************
     * Player
     * destructor

***********************************************************************/
ach::Player::~Player()
{
	delete character;
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

	character->aim = sf::Vector2f(0.0f, 0.0f);

	character->dir.y = 0;

	character->phys.vel.x  = 0.0f;
	character->phys.moving = false;

	if (ctrl->keys[ach::ControlAction::caLeft ].state) move(-1);
	if (ctrl->keys[ach::ControlAction::caRight].state) move( 1);

	character->phys.jumpdown = ctrl->keys[ach::ControlAction::caJump].state &&
	                           ctrl->keys[ach::ControlAction::caDown].state;

	if (ctrl->keys[ach::ControlAction::caJump ].pressed) character->jump();
	if (ctrl->keys[ach::ControlAction::caShot ].state  ) character->shot();

	if (ctrl->keys[ach::ControlAction::caUp  ].state) character->dir.y = -1;
	if (ctrl->keys[ach::ControlAction::caDown].state) character->dir.y =  1;


	character->aim = sf::Vector2f(character->dir);

	if (character->dir.y == -1 && !character->phys.moving)
		character->aim.x = 0.0f;
}



/***********************************************************************
     * Player
     * reset

***********************************************************************/
void ach::Player::reset()
{
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
