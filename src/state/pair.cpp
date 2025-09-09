#include "meta/headers.hpp"


/***********************************************************************
     * pairGameState

***********************************************************************/
ach::Pair<ach::GameState> pairGameState[] =
{
	{.num = ach::GameState::gsStart  , .str = "start"  },
	{.num = ach::GameState::gsMenu   , .str = "menu"   },
	{.num = ach::GameState::gsGame   , .str = "game"   },
	{.num = ach::GameState::gsCredits, .str = "credits"},
	{.num = ach::GameState::gsFinish , .str = "finish" },
	{.num = ach::GameState::gsEnd    , .str = "end"    },

	{.num = ach::GameState::gsNone   , .str = NULL     },
};
