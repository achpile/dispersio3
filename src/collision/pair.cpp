#include "meta/headers.hpp"


/***********************************************************************
     * pairPhysType

***********************************************************************/
ach::Pair<ach::PhysType> pairPhysType[] =
{
	{.num = ach::PhysType::ptSolid   , .str = "solid"   },
	{.num = ach::PhysType::ptPlatform, .str = "platform"},
	{.num = ach::PhysType::ptBarrier , .str = "barrier" },
	{.num = ach::PhysType::ptDeath   , .str = "death"   },

	{.num = ach::PhysType::ptSolid   , .str = NULL      },
};
