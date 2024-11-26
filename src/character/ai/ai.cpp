#include "meta/headers.hpp"


/***********************************************************************
     * AI
     * constructor

***********************************************************************/
ach::AI::AI(ach::Character *_owner)
{
	owner = _owner;

	owner->enemy = true;
}



/***********************************************************************
     * AI
     * destructor

***********************************************************************/
ach::AI::~AI()
{
}



/***********************************************************************
     * AI
     * control

***********************************************************************/
void ach::AI::control()
{
	owner->phys.vel.x = 0.0f;
	owner->phys.vel.y = 0.0f;
	owner->phys.acc.x = 0.0f;
	owner->phys.acc.y = 0.0f;
}



/***********************************************************************
     * AI
     * update

***********************************************************************/
void ach::AI::update()
{
	control();
	aim();
}



/***********************************************************************
     * AI
     * create

***********************************************************************/
ach::AI* ach::AI::create(ach::Character *_owner, ach::AIType type)
{
	switch (type)
	{
		case ach::AIType::aiIdle  : return new ach::AI      (_owner);
		case ach::AIType::aiPlayer: return new ach::AIPlayer(_owner);
	}

	return new ach::AI(_owner);
}
