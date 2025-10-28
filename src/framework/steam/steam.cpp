#include "meta/headers.hpp"


/***********************************************************************
     * Steam
     * constructor

***********************************************************************/
ach::Steam::Steam()
{
	initialized = false;

	if (!SteamAPI_IsSteamRunning())
		return;

	FILE *fp = fopen(FILE_APPID, "w");

	if (!fp)
		return;

	fprintf(fp, "%s\n", PROJECT_ID);
	fclose(fp);

	initialized = SteamAPI_Init();

	if (!initialized)
		return;

	ID = SteamAPI_ISteamUser_GetSteamID((intptr_t)SteamUser());

	sclient = SteamClient();
	spipe   = SteamAPI_ISteamClient_CreateSteamPipe((intptr_t)sclient);
	sutils  = SteamAPI_ISteamClient_GetISteamUtils((intptr_t)sclient, spipe, STEAMUTILS_INTERFACE_VERSION);

	if (!sutils)
		return;
}



/***********************************************************************
     * Steam
     * destructor

***********************************************************************/
ach::Steam::~Steam()
{
	unlink(FILE_APPID);

	if (initialized)
		SteamAPI_Shutdown();
}
