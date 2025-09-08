#include "meta/headers.hpp"


/***********************************************************************
     * pairArcade

***********************************************************************/
ach::Pair<ach::ArcadeGame> pairArcade[] =
{
	{.num = ach::ArcadeGame::BrickOut, .str = "BrickOut"},
	{.num = ach::ArcadeGame::Hexagon , .str = "Hexagon" },
	{.num = ach::ArcadeGame::Race    , .str = "Race"    },
	{.num = ach::ArcadeGame::Snake   , .str = "Snake"   },
	{.num = ach::ArcadeGame::Simon   , .str = "Simon"   },
	{.num = ach::ArcadeGame::Tetris  , .str = "Tetris"  },

	{.num = ach::ArcadeGame::None    , .str = NULL      },
	{.num = ach::ArcadeGame::Count   , .str = NULL      },
};



/***********************************************************************
     * pairArcadeName

***********************************************************************/
ach::Pair<ach::ArcadeGame> pairArcadeName[] =
{
	{.num = ach::ArcadeGame::None    , .str = "OUT OF ORDER"},
	{.num = ach::ArcadeGame::BrickOut, .str = "BRICK OUT"   },
	{.num = ach::ArcadeGame::Hexagon , .str = "HEXAGON"     },
	{.num = ach::ArcadeGame::Race    , .str = "F1-RACE"     },
	{.num = ach::ArcadeGame::Snake   , .str = "SNAKE"       },
	{.num = ach::ArcadeGame::Simon   , .str = "SIMON"       },
	{.num = ach::ArcadeGame::Tetris  , .str = "TETЯIS"      },

	{.num = ach::ArcadeGame::None    , .str = NULL          },
	{.num = ach::ArcadeGame::Count   , .str = NULL          },
};



/***********************************************************************
     * pairArcadeFlag

***********************************************************************/
ach::Pair<ach::ArcadeGame> pairArcadeFlag[] =
{
	{.num = ach::ArcadeGame::None    , .str = ""               },
	{.num = ach::ArcadeGame::BrickOut, .str = "HasGameArkanoid"},
	{.num = ach::ArcadeGame::Hexagon , .str = "HasGameHexagon" },
	{.num = ach::ArcadeGame::Race    , .str = "HasGameF1"      },
	{.num = ach::ArcadeGame::Snake   , .str = "HasGameSnake"   },
	{.num = ach::ArcadeGame::Simon   , .str = "HasGameSimon"   },
	{.num = ach::ArcadeGame::Tetris  , .str = "HasGameTetris"  },

	{.num = ach::ArcadeGame::None    , .str = NULL             },
	{.num = ach::ArcadeGame::Count   , .str = NULL             },
};
