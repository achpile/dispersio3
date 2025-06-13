#include "meta/headers.hpp"


/***********************************************************************
     * AIPlayer
     * constructor

***********************************************************************/
ach::AIPlayer::AIPlayer(ach::Character *_owner, json_t *obj) : AI(_owner, obj)
{
	splash  = db->getSound(json_object_get_branch_string(dm->data, "Data.Game.Meta.SFX.Splash"));

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
     * physics

***********************************************************************/
void ach::AIPlayer::physics()
{
	ground();

	owner->dir.y      = owner->phys.gravity;
	owner->phys.acc.y = owner->base->gravity * (owner->phys.water ? PHYS_WATER : 1.0f) * owner->phys.gravity;
	owner->jumping    = owner->base->jumping * (owner->phys.water ? PHYS_WATER : 1.0f) * owner->phys.gravity;
	owner->speed      = owner->base->speed   * (owner->phys.water ? PHYS_WATER : 1.0f);

	if (owner->phys.water)
	{
		owner->phys.vel.y = interval_set(owner->phys.vel.y, -PHYS_MAX_VEL, PHYS_WATER_FALL);

		if (!water)
			sm->play(splash->snd);
	}

	water = owner->phys.water;
}



/***********************************************************************
     * AIPlayer
     * control

***********************************************************************/
void ach::AIPlayer::control()
{
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
	water  = true;
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
