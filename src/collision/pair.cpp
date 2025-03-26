#include "meta/headers.hpp"


/***********************************************************************
     * pairPhysType

***********************************************************************/
ach::Pair<ach::PhysType> pairPhysType[] =
{
	{.num = ach::PhysType::ptSolid   , .str = "phys_solid"   },
	{.num = ach::PhysType::ptPlatform, .str = "phys_platform"},
	{.num = ach::PhysType::ptBarrier , .str = "phys_barrier" },
	{.num = ach::PhysType::ptDeath   , .str = "phys_death"   },
	{.num = ach::PhysType::ptBounce  , .str = "phys_bounce"  },

	{.num = ach::PhysType::ptSolid   , .str = NULL           },
};
