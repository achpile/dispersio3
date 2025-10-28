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
}



/***********************************************************************
     * LeaderboardEntry
     * destructor

***********************************************************************/
ach::LeaderboardEntry::~LeaderboardEntry()
{
}
