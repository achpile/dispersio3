#include "meta/headers.hpp"


/***********************************************************************
     * pairTileLayer

***********************************************************************/
ach::Pair<ach::TileLayer> pairTileLayer[] =
{
	{.num = ach::TileLayer::tlBack , .str = "back" },
	{.num = ach::TileLayer::tlWall , .str = "wall" },
	{.num = ach::TileLayer::tlBlock, .str = "block"},
	{.num = ach::TileLayer::tlDecor, .str = "decor"},

	{.num = ach::TileLayer::tlWall , .str = NULL   },
};
