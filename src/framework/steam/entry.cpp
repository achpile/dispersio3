#include "meta/headers.hpp"


/***********************************************************************
     * LeaderboardEntry
     * constructor

***********************************************************************/
ach::LeaderboardEntry::LeaderboardEntry(unsigned long _rank, unsigned int _score, bool time, CSteamID ID)
{
	rank  = _rank;
	score = _score;
	name  = std::string(SteamFriends()->GetFriendPersonaName(ID));
	own   = ID == steam->ID;

	id    = std::to_string(rank) + ". " + name;
	value = (time) ? str_time(((float)score) / 1000.0f) : sf::String(std::to_string(score));
}



/***********************************************************************
     * LeaderboardEntry
     * destructor

***********************************************************************/
ach::LeaderboardEntry::~LeaderboardEntry()
{
}
