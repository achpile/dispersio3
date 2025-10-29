#ifndef __FRAMEWORK_STEAM_STEAM
#define __FRAMEWORK_STEAM_STEAM


namespace ach
{
	struct Steam
	{
		std::vector<ach::Leaderboard*> leaderboards;
		std::vector<ach::Leaderboard*> highscores;

		CSteamID      ID;

		ISteamClient *sclient;
		ISteamUtils  *sutils;
		HSteamPipe    spipe;

		bool initialized;


		 Steam();
		~Steam();

		void update();
		bool check();

		void setAchievement(const char *name);
		bool getAchievement(const char *name);

		const char* language();
	};
}

#endif
