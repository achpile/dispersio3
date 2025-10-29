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

	list_delete(leaderboards);
	list_delete(highscores);

	if (initialized)
		SteamAPI_Shutdown();
}



/***********************************************************************
     * Steam
     * update

***********************************************************************/
void ach::Steam::update()
{
	if (!initialized)
		return;

	list_foreach(leaderboards)
		leaderboards[i]->update((intptr_t)sutils);

	list_foreach(highscores)
		highscores[i]->update((intptr_t)sutils);
}



/***********************************************************************
     * Steam
     * check

***********************************************************************/
bool ach::Steam::check()
{
	if (!initialized)
		return false;

	list_foreach(leaderboards)
		if (!leaderboards[i]->handle)
			return false;

	list_foreach(highscores)
		if (!highscores[i]->handle)
			return false;

	return true;
}



/***********************************************************************
     * Steam
     * setAchievement

***********************************************************************/
void ach::Steam::setAchievement(const char *name)
{
	if (!initialized)
		return;

	SteamUserStats()->SetAchievement(name);
	SteamUserStats()->StoreStats();
}



/***********************************************************************
     * Steam
     * getAchievement

***********************************************************************/
bool ach::Steam::getAchievement(const char *name)
{
	if (!initialized)
		return false;

	bool res;

	if (SteamUserStats()->GetAchievement(name, &res))
		return res;

	return false;
}



/***********************************************************************
     * Steam
     * language

***********************************************************************/
const char* ach::Steam::language()
{
	if (!initialized)
		return "english";

	return SteamApps()->GetCurrentGameLanguage();
}
