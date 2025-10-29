#include "meta/headers.hpp"


/***********************************************************************
     * pairLeaderboardStatus

***********************************************************************/
ach::Pair<ach::LeaderboardStatus> pairLeaderboardStatus[] =
{
	{.num = ach::LeaderboardStatus::lsLoading, .str = "Loading"},
	{.num = ach::LeaderboardStatus::lsFailed , .str = "Failed" },
	{.num = ach::LeaderboardStatus::lsNoData , .str = "NoData" },

	{.num = ach::LeaderboardStatus::lsSuccess, .str = NULL     },
};



/***********************************************************************
     * pairLeaderboardClass

***********************************************************************/
ach::Pair<ach::LeaderboardClass> pairLeaderboardClass[] =
{
	{.num = ach::LeaderboardClass::lcNearest, .str = "Nearest"},
	{.num = ach::LeaderboardClass::lcFriends, .str = "Friends"},
	{.num = ach::LeaderboardClass::lcBest   , .str = "Best"   },

	{.num = ach::LeaderboardClass::lcBest   , .str = NULL     },
};
