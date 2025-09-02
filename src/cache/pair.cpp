#include "meta/headers.hpp"


/***********************************************************************
     * pairLevelMode

***********************************************************************/
ach::Pair<ach::LevelMode> pairLevelMode[] =
{
	{.num = ach::LevelMode::lmTraining  , .str = "training"  },
	{.num = ach::LevelMode::lmDream     , .str = "dream"     },
	{.num = ach::LevelMode::lmNavigation, .str = "navigation"},
	{.num = ach::LevelMode::lmReplay    , .str = "replay"    },

	{.num = ach::LevelMode::lmTraining  , .str = NULL        },
};



/***********************************************************************
     * pairLevelModeMenu

***********************************************************************/
ach::Pair<ach::LevelMode> pairLevelModeMenu[] =
{
	{.num = ach::LevelMode::lmTraining  , .str = "UI.Menu.Level.Training"  },
	{.num = ach::LevelMode::lmDream     , .str = "UI.Menu.Level.Dream"     },
	{.num = ach::LevelMode::lmNavigation, .str = "UI.Menu.Level.Navigation"},
	{.num = ach::LevelMode::lmReplay    , .str = "UI.Menu.Level.Replay"    },

	{.num = ach::LevelMode::lmTraining  , .str = NULL                      },
};



/***********************************************************************
     * pairLevelModeRevert

***********************************************************************/
ach::Pair<ach::LevelMode> pairLevelModeRevert[] =
{
	{.num = ach::LevelMode::lmTraining  , .str = "UI.Menu.Level.Finish"},
	{.num = ach::LevelMode::lmDream     , .str = "UI.Menu.Level.WakeUp"},
	{.num = ach::LevelMode::lmReplay    , .str = "UI.Menu.Level.Future"},
	{.num = ach::LevelMode::lmNavigation, .str = NULL                  },
};
