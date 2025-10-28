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
	};
}

#endif
