#include "meta/headers.hpp"


/***********************************************************************
     * pairDirection

***********************************************************************/
ach::Pair pairDirection[] =
{
	{.num = ach::Direction::dUp   , .str = "up"   },
	{.num = ach::Direction::dDown , .str = "down" },
	{.num = ach::Direction::dLeft , .str = "left" },
	{.num = ach::Direction::dRight, .str = "right"},

	{.num = ach::Direction::dCount, .str = NULL   },
};



/***********************************************************************
     * pairOrientation

***********************************************************************/
ach::Pair pairOrientation[] =
{
	{.num = ach::Orientation::oVertical  , .str = "vertical"  },
	{.num = ach::Orientation::oHorizontal, .str = "horizontal"},

	{.num = ach::Orientation::oCount     , .str = NULL        },
};
