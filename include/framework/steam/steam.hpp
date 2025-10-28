#ifndef __FRAMEWORK_STEAM_STEAM
#define __FRAMEWORK_STEAM_STEAM


namespace ach
{
	struct Steam
	{
		CSteamID      ID;

		ISteamClient *sclient;
		ISteamUtils  *sutils;
		HSteamPipe    spipe;

		bool initialized;


		 Steam();
		~Steam();

		void setAchievement(const char *name);
		bool getAchievement(const char *name);
	};
}

#endif
