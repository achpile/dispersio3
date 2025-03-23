#include "meta/headers.hpp"


/***********************************************************************
     * AIPlayer
     * constructor

***********************************************************************/
ach::AIPlayer::AIPlayer(ach::Character *_owner, json_t *obj) : AI(_owner, obj)
{
	owner->enemy = false;
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
	ground();

	jumped &= ctrl->keys[ach::ControlAction::caJump].state;

	owner->phys.vel.x    = 0.0f;
	owner->phys.moving   = false;
	owner->phys.jumpdown = ctrl->keys[ach::ControlAction::caDown].state;

	if (ctrl->keys[ach::ControlAction::caLeft ].state) move(-1);
	if (ctrl->keys[ach::ControlAction::caRight].state) move( 1);

	if (ctrl->keys[ach::ControlAction::caJump ].state  ) jump();
	if (ctrl->keys[ach::ControlAction::caUp   ].pressed) owner->use();
}



/***********************************************************************
     * AIPlayer
     * reset

***********************************************************************/
void ach::AIPlayer::reset()
{
	jumped = false;
}



/***********************************************************************
     * AIPlayer
     * collide

***********************************************************************/
void ach::AIPlayer::collide(ach::PhysLine *line)
{
	if (line->type == ach::PhysType::ptDeath)
		owner->die();
}



/***********************************************************************
     * AIPlayer
     * move

***********************************************************************/
void ach::AIPlayer::move(int d)
{
	owner->dir.x = d;
	owner->move(d);
}



/***********************************************************************
     * AIPlayer
     * jump

***********************************************************************/
void ach::AIPlayer::jump()
{
	if (jumped)
		return;

	if (owner->jump())
		jumped = true;
}
