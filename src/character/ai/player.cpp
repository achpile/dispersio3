#include "meta/headers.hpp"


/***********************************************************************
     * AIPlayer
     * constructor

***********************************************************************/
ach::AIPlayer::AIPlayer(ach::Character *_owner) : AI(_owner)
{
}



/***********************************************************************
     * AIPlayer
     * destructor

***********************************************************************/
ach::AIPlayer::~AIPlayer()
{
}



/***********************************************************************
     * AIPlayer
     * control

***********************************************************************/
void ach::AIPlayer::control()
{
	owner->phys.vel.x  = 0.0f;
	owner->phys.moving = false;

	if (ctrl->keys[ach::ControlAction::caLeft ].state) move(-1, ctrl->keys[ach::ControlAction::caHold].state);
	if (ctrl->keys[ach::ControlAction::caRight].state) move( 1, ctrl->keys[ach::ControlAction::caHold].state);

	owner->phys.jumpdown = ctrl->keys[ach::ControlAction::caJump].state &&
	                           ctrl->keys[ach::ControlAction::caDown].state;

	if (ctrl->keys[ach::ControlAction::caJump ].pressed) owner->jump();
	if (ctrl->keys[ach::ControlAction::caShot ].state  ) owner->shot();
}



/***********************************************************************
     * AIPlayer
     * aim

***********************************************************************/
void ach::AIPlayer::aim()
{
	owner->aim = sf::Vector2f(0.0f, 0.0f);

	if (ctrl->keys[ach::ControlAction::caLeft ].state) owner->aim.x = -1.0f;
	if (ctrl->keys[ach::ControlAction::caRight].state) owner->aim.x =  1.0f;

	if (ctrl->keys[ach::ControlAction::caUp  ].state) owner->aim.y = -1.0f;
	if (ctrl->keys[ach::ControlAction::caDown].state) owner->aim.y =  1.0f;

	if (owner->aim.y >= 0)
		owner->aim.x = owner->dir.x;
}



/***********************************************************************
     * AIPlayer
     * move

***********************************************************************/
void ach::AIPlayer::move(int d, bool hold)
{
	owner->dir.x = d;

	if (!hold)
		owner->move(d);
}
