#include "meta/headers.hpp"


/***********************************************************************
     * pairArcade

***********************************************************************/
ach::Pair<ach::ArcadeGame> pairArcade[] =
{
	{.num = ach::ArcadeGame::BrickOut, .str = "BrickOut"},
	{.num = ach::ArcadeGame::F1      , .str = "F1"      },
	{.num = ach::ArcadeGame::Hexagon , .str = "Hexagon" },
	{.num = ach::ArcadeGame::Snake   , .str = "Snake"   },
	{.num = ach::ArcadeGame::Simon   , .str = "Simon"   },
	{.num = ach::ArcadeGame::Tetris  , .str = "Tetris"  },

	{.num = ach::ArcadeGame::None    , .str = NULL      },
};



/***********************************************************************
     * pairArcadeName

***********************************************************************/
ach::Pair<ach::ArcadeGame> pairArcadeName[] =
{
	{.num = ach::ArcadeGame::None    , .str = "OUT OF ORDER"},
	{.num = ach::ArcadeGame::BrickOut, .str = "BRICK OUT"   },
	{.num = ach::ArcadeGame::F1      , .str = "F1-RACE"     },
	{.num = ach::ArcadeGame::Hexagon , .str = "HEXAGON"     },
	{.num = ach::ArcadeGame::Snake   , .str = "SNAKE"       },
	{.num = ach::ArcadeGame::Simon   , .str = "SIMON"       },
	{.num = ach::ArcadeGame::Tetris  , .str = "TETЯIS"      },

	{.num = ach::ArcadeGame::None    , .str = NULL          },
};
