#include "meta/headers.hpp"


/***********************************************************************
     * pairAI

***********************************************************************/
ach::Pair<ach::AIType> pairAI[] =
{
	{.num = ach::AIType::aiIdle  , .str = "idle"  },
	{.num = ach::AIType::aiPlayer, .str = "player"},
	{.num = ach::AIType::aiFloat , .str = "float" },
	{.num = ach::AIType::aiCrawl , .str = "crawl" },
	{.num = ach::AIType::aiCannon, .str = "cannon"},
	{.num = ach::AIType::aiSniper, .str = "sniper"},

	{.num = ach::AIType::aiIdle  , .str = NULL    },
};
