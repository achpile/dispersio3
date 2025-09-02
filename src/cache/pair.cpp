#include "meta/headers.hpp"


/***********************************************************************
     * pairGameMode

***********************************************************************/
ach::Pair<ach::GameMode> pairGameMode[] =
{
	{.num = ach::GameMode::gmNormal, .str = "normal"},
	{.num = ach::GameMode::gmHard  , .str = "hard"  },

	{.num = ach::GameMode::gmNormal, .str = NULL    },
};



/***********************************************************************
     * pairLevelList

***********************************************************************/
ach::Pair<ach::LevelList> pairLevelList[] =
{
	{.num = ach::LevelList::llTraining  , .str = "training"  },
	{.num = ach::LevelList::llDream     , .str = "dream"     },
	{.num = ach::LevelList::llNavigation, .str = "navigation"},
	{.num = ach::LevelList::llReplay    , .str = "replay"    },

	{.num = ach::LevelList::llTraining  , .str = NULL        },
};
