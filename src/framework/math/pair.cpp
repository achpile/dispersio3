#include "meta/headers.hpp"


/***********************************************************************
     * pairDirection

***********************************************************************/
ach::Pair<ach::Direction> pairDirection[] =
{
	{.num = ach::Direction::dUp   , .str = "up"   },
	{.num = ach::Direction::dDown , .str = "down" },
	{.num = ach::Direction::dLeft , .str = "left" },
	{.num = ach::Direction::dRight, .str = "right"},
	{.num = ach::Direction::dCount, .str = "none" },

	{.num = ach::Direction::dCount, .str = NULL   },
};



/***********************************************************************
     * pairOrientation

***********************************************************************/
ach::Pair<ach::Orientation> pairOrientation[] =
{
	{.num = ach::Orientation::oVertical  , .str = "vertical"  },
	{.num = ach::Orientation::oHorizontal, .str = "horizontal"},
	{.num = ach::Orientation::oCount     , .str = "none"      },

	{.num = ach::Orientation::oCount     , .str = NULL        },
};
