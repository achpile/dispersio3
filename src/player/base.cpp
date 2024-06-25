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
	// TODO : move to character::update
	if (character->dead)
		return;

	character->phys.vel.x  = 0.0f;
	character->phys.moving = false;

	if (ctrl->keys[ach::ControlAction::caLeft ].state) move(-1, ctrl->keys[ach::ControlAction::caHold].state);
	if (ctrl->keys[ach::ControlAction::caRight].state) move( 1, ctrl->keys[ach::ControlAction::caHold].state);

	character->phys.jumpdown = ctrl->keys[ach::ControlAction::caJump].state &&
	                           ctrl->keys[ach::ControlAction::caDown].state;

	if (ctrl->keys[ach::ControlAction::caJump ].pressed) character->jump();
	if (ctrl->keys[ach::ControlAction::caShot ].state  ) character->shot();

	aim();
}



/***********************************************************************
     * Player
     * aim

***********************************************************************/
void ach::Player::aim()
{
	character->aim = sf::Vector2f(0.0f, 0.0f);

	if (ctrl->keys[ach::ControlAction::caLeft ].state) character->aim.x = -1.0f;
	if (ctrl->keys[ach::ControlAction::caRight].state) character->aim.x =  1.0f;

	if (ctrl->keys[ach::ControlAction::caUp  ].state) character->aim.y = -1.0f;
	if (ctrl->keys[ach::ControlAction::caDown].state) character->aim.y =  1.0f;

	if (character->aim.y >= 0)
		character->aim.x = character->dir.x;
}



/***********************************************************************
     * Player
     * respawn

***********************************************************************/
void ach::Player::respawn(sf::Vector2f spawn)
{
	character->respawn(spawn);
}



/***********************************************************************
     * Player
     * move

***********************************************************************/
void ach::Player::move(int d, bool hold)
{
	character->dir.x = d;

	if (!hold)
		character->move(d);
}
