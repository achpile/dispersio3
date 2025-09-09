#include "meta/headers.hpp"


/***********************************************************************
     * pairArcade

***********************************************************************/
ach::Pair<ach::ArcadeGame> pairArcade[] =
{
	{.num = ach::ArcadeGame::agBrickOut, .str = "BrickOut"},
	{.num = ach::ArcadeGame::agHexagon , .str = "Hexagon" },
	{.num = ach::ArcadeGame::agRace    , .str = "Race"    },
	{.num = ach::ArcadeGame::agSnake   , .str = "Snake"   },
	{.num = ach::ArcadeGame::agSimon   , .str = "Simon"   },
	{.num = ach::ArcadeGame::agTetris  , .str = "Tetris"  },

	{.num = ach::ArcadeGame::agNone    , .str = NULL      },
	{.num = ach::ArcadeGame::agCount   , .str = NULL      },
};



/***********************************************************************
     * pairArcadeName

***********************************************************************/
ach::Pair<ach::ArcadeGame> pairArcadeName[] =
{
	{.num = ach::ArcadeGame::agNone    , .str = "OUT OF ORDER"},
	{.num = ach::ArcadeGame::agBrickOut, .str = "BRICK OUT"   },
	{.num = ach::ArcadeGame::agHexagon , .str = "HEXAGON"     },
	{.num = ach::ArcadeGame::agRace    , .str = "F1-RACE"     },
	{.num = ach::ArcadeGame::agSnake   , .str = "SNAKE"       },
	{.num = ach::ArcadeGame::agSimon   , .str = "SIMON"       },
	{.num = ach::ArcadeGame::agTetris  , .str = "TETЯIS"      },

	{.num = ach::ArcadeGame::agNone    , .str = NULL          },
	{.num = ach::ArcadeGame::agCount   , .str = NULL          },
};



/***********************************************************************
     * pairArcadeFlag

***********************************************************************/
ach::Pair<ach::ArcadeGame> pairArcadeFlag[] =
{
	{.num = ach::ArcadeGame::agNone    , .str = ""               },
	{.num = ach::ArcadeGame::agBrickOut, .str = "HasGameArkanoid"},
	{.num = ach::ArcadeGame::agHexagon , .str = "HasGameHexagon" },
	{.num = ach::ArcadeGame::agRace    , .str = "HasGameF1"      },
	{.num = ach::ArcadeGame::agSnake   , .str = "HasGameSnake"   },
	{.num = ach::ArcadeGame::agSimon   , .str = "HasGameSimon"   },
	{.num = ach::ArcadeGame::agTetris  , .str = "HasGameTetris"  },

	{.num = ach::ArcadeGame::agNone    , .str = NULL             },
	{.num = ach::ArcadeGame::agCount   , .str = NULL             },
};
