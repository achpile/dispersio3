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

	owner->phys.vel.x    = 0.0f;
	owner->phys.moving   = false;
	owner->phys.jumpdown = ctrl->keys[ach::ControlAction::caDown].state;

	if (ctrl->keys[ach::ControlAction::caLeft ].state) move(-1);
	if (ctrl->keys[ach::ControlAction::caRight].state) move( 1);

	if (ctrl->keys[ach::ControlAction::caJump ].pressed) owner->jump();
	if (ctrl->keys[ach::ControlAction::caUp   ].pressed) owner->use();
}



/***********************************************************************
     * AIPlayer
     * reset

***********************************************************************/
void ach::AIPlayer::reset()
{
	owner->phys.acc.y = PHYS_GRAVITY;
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
