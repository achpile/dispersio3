#include "meta/headers.hpp"


/***********************************************************************
     * AI
     * constructor

***********************************************************************/
ach::AI::AI(ach::Character *_owner)
{
	owner = _owner;
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
     * create

***********************************************************************/
ach::AI* ach::AI::create(ach::Character *_owner, ach::AIType type)
{
	switch (type)
	{
		case ach::AIType::aiIdle  : return new ach::AI      (_owner);
		case ach::AIType::aiPlayer: return new ach::AIPlayer(_owner);

		default                   : return new ach::AI      (_owner);
	}
}
