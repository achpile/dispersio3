#include "meta/headers.hpp"


/***********************************************************************
     * pairAchievement

***********************************************************************/
ach::Pair<ach::Achievement> pairAchievement[] =
{
	{.num = ach::Achievement::acMilitaryBase, .str = "MilitaryBase"},
	{.num = ach::Achievement::acLaunchPad   , .str = "LaunchPad"   },
	{.num = ach::Achievement::acCave        , .str = "Cave"        },
	{.num = ach::Achievement::acLab         , .str = "Lab"         },
	{.num = ach::Achievement::acForest      , .str = "Forest"      },
	{.num = ach::Achievement::acFactory     , .str = "Factory"     },
	{.num = ach::Achievement::acTemple      , .str = "Temple"      },
	{.num = ach::Achievement::acDuck        , .str = "Duck"        },
	{.num = ach::Achievement::acIsland      , .str = "Island"      },
	{.num = ach::Achievement::acPlumber     , .str = "Plumber"     },
	{.num = ach::Achievement::acRobot       , .str = "Robot"       },
	{.num = ach::Achievement::acMattress    , .str = "Mattress"    },
	{.num = ach::Achievement::acTimeMachine , .str = "TimeMachine" },
	{.num = ach::Achievement::acDonation    , .str = "Donation"    },
	{.num = ach::Achievement::acEasy        , .str = "Easy"        },
	{.num = ach::Achievement::acNormal      , .str = "Normal"      },
	{.num = ach::Achievement::acHard        , .str = "Hard"        },
	{.num = ach::Achievement::acCollectGames, .str = "CollectGames"},
	{.num = ach::Achievement::acCollectFresh, .str = "CollectFresh"},
	{.num = ach::Achievement::acCollectAll  , .str = "CollectAll"  },
	{.num = ach::Achievement::acBrickOut    , .str = "BrickOut"    },
	{.num = ach::Achievement::acHexagon     , .str = "Hexagon"     },
	{.num = ach::Achievement::acRace        , .str = "Race"        },
	{.num = ach::Achievement::acSnake       , .str = "Snake"       },
	{.num = ach::Achievement::acSimon       , .str = "Simon"       },
	{.num = ach::Achievement::acTetris      , .str = "Tetris"      },

	{.num = ach::Achievement::acCount       , .str = NULL          },
};



/***********************************************************************
     * pairAchievementFlag

***********************************************************************/
ach::Pair<ach::Achievement> pairAchievementFlag[] =
{
	{.num = ach::Achievement::acMattress    , .str = "PlacedMattress"     },
	{.num = ach::Achievement::acTimeMachine , .str = "PlacedFluxCapacitor"},
	{.num = ach::Achievement::acDonation    , .str = "MoneyDonated"       },

	{.num = ach::Achievement::acCount       , .str = NULL                 },
};



/***********************************************************************
     * pairDifficulty

***********************************************************************/
ach::Pair<ach::Difficulty> pairDifficulty[] =
{
	{.num = ach::Difficulty::gdEasy  , .str = "easy"  },
	{.num = ach::Difficulty::gdNormal, .str = "normal"},
	{.num = ach::Difficulty::gdHard  , .str = "hard"  },

	{.num = ach::Difficulty::gdEasy  , .str = NULL    },
};



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
