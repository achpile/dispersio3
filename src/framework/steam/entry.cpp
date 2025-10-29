#include "meta/headers.hpp"


/***********************************************************************
     * LeaderboardEntry
     * constructor

***********************************************************************/
ach::LeaderboardEntry::LeaderboardEntry(unsigned long _rank, unsigned int _score, CSteamID ID)
{
	rank  = _rank;
	score = _score;
	name  = std::string(SteamFriends()->GetFriendPersonaName(ID));
	own   = ID == steam->ID;

	id    = std::to_string(rank) + ". " + name;
	value = std::to_string(score);
	time  = str_time(((float)score) / 1000.0f);
}



/***********************************************************************
     * LeaderboardEntry
     * destructor

***********************************************************************/
ach::LeaderboardEntry::~LeaderboardEntry()
{
}
