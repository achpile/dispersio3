#ifndef __FRAMEWORK_STEAM_STEAM
#define __FRAMEWORK_STEAM_STEAM


namespace ach
{
	struct Steam
	{
		std::vector<ach::Leaderboard*> leaderboards;

		CSteamID      ID;

		ISteamClient *sclient;
		ISteamUtils  *sutils;
		HSteamPipe    spipe;

		bool initialized;


		 Steam();
		~Steam();

		void update();
		void init();
		bool check();

		void setAchievement(const char *name);
		bool getAchievement(const char *name);

		void         setHighscore(const char *name, unsigned int score);
		unsigned int getHighscore(const char *name);
		unsigned int getBestscore(const char *name);

		ach::Leaderboard *getLeaderboard(const char *name);

		const char* language();
	};
}

#endif
