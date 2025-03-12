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
     * update

***********************************************************************/
void ach::AI::update()
{
	control();
	aim();
}



/***********************************************************************
     * AI
     * ground

***********************************************************************/
void ach::AI::ground()
{
	if (owner->phys.grounded)
		owner->phys.vel.y = 1.5f * owner->speed;
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
		case ach::AIType::aiSniper: return new ach::AISniper(_owner, obj);
	}

	return new ach::AI(_owner, obj);
}
