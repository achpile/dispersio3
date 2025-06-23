#include "meta/headers.hpp"


/***********************************************************************
     * AI
     * constructor

***********************************************************************/
ach::AI::AI(ach::Character *_owner, json_t*)
{
	owner  = _owner;
	target = NULL;

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
	physics();
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
		owner->phys.vel.y = 2.0f * owner->phys.slope * owner->speed * owner->phys.gravity;
}



/***********************************************************************
     * AI
     * search

***********************************************************************/
void ach::AI::search()
{
	ach::Character *candidate = NULL;
	float dist = 0.0f;

	target = NULL;

	list_foreach(owner->world->map->characters)
	{
		candidate = owner->world->map->characters[i];

		if (owner->enemy == candidate->enemy)
			continue;

		if (!candidate->visible())
			continue;

		if (!target || vector_len(owner->phys.pos - candidate->phys.pos) < dist)
		{
			target = candidate;
			dist   = vector_len(owner->phys.pos - candidate->phys.pos);
		}
	}

	if (!target)
		owner->weapon->cooldown.reset();
}



/***********************************************************************
     * AI
     * create

***********************************************************************/
ach::AI* ach::AI::create(ach::Character *_owner, ach::AIType type, json_t *obj)
{
	switch (type)
	{
		case ach::AIType::aiIdle   : return new ach::AI       (_owner, obj);
		case ach::AIType::aiPlayer : return new ach::AIPlayer (_owner, obj);
		case ach::AIType::aiFloat  : return new ach::AIFloat  (_owner, obj);
		case ach::AIType::aiCrawl  : return new ach::AICrawl  (_owner, obj);
		case ach::AIType::aiCannon : return new ach::AICannon (_owner, obj);
		case ach::AIType::aiSniper : return new ach::AISniper (_owner, obj);
		case ach::AIType::aiJumper : return new ach::AIJumper (_owner, obj);
		case ach::AIType::aiFollow : return new ach::AIFollow (_owner, obj);
		case ach::AIType::aiLeveler: return new ach::AILeveler(_owner, obj);
	}

	return new ach::AI(_owner, obj);
}
