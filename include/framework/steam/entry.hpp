#ifndef __FRAMEWORK_STEAM_ENTRY
#define __FRAMEWORK_STEAM_ENTRY


namespace ach
{
	struct LeaderboardEntry
	{
		sf::String    id;
		sf::String    value;
		sf::String    time;

		std::string   name;

		unsigned long rank;
		unsigned int  score;
		bool          own;


		 LeaderboardEntry(unsigned long _rank, unsigned int _score, CSteamID ID);
		~LeaderboardEntry();
	};
}

#endif
