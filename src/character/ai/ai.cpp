#include "meta/headers.hpp"


/***********************************************************************
     * AI
     * constructor

***********************************************************************/
ach::AI::AI(ach::Character *_owner, json_t*)
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
     * collide

***********************************************************************/
void ach::AI::collide(ach::PhysLine*)
{
}



/***********************************************************************
     * AI
     * create

***********************************************************************/
ach::AI* ach::AI::create(ach::Character *_owner, ach::AIType type, json_t *obj)
{
	switch (type)
	{
		case ach::AIType::aiIdle  : return new ach::AI      (_owner, obj);
		case ach::AIType::aiPlayer: return new ach::AIPlayer(_owner, obj);
		case ach::AIType::aiFloat : return new ach::AIFloat (_owner, obj);
		case ach::AIType::aiCrawl : return new ach::AICrawl (_owner, obj);
		case ach::AIType::aiCannon: return new ach::AICannon(_owner, obj);
	}

	return new ach::AI(_owner, obj);
}
