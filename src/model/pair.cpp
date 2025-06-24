#include "meta/headers.hpp"


/***********************************************************************
     * pairModel

***********************************************************************/
ach::Pair<ach::ModelType> pairModel[] =
{
	{.num = ach::ModelType::mtNone  , .str = "none"  },
	{.num = ach::ModelType::mtSimple, .str = "simple"},
	{.num = ach::ModelType::mtPlayer, .str = "player"},
	{.num = ach::ModelType::mtJumper, .str = "jumper"},
	{.num = ach::ModelType::mtMoving, .str = "moving"},

	{.num = ach::ModelType::mtNone  , .str = NULL    },
};
