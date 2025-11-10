#include "meta/headers.hpp"


/***********************************************************************
     * Steam
     * constructor

***********************************************************************/
ach::Steam::Steam()
{
	initialized = false;

	if (!SteamAPI_IsSteamRunning())
	{
		logger->log(ach::LogLevel::llWarning, "Steam is not running");
		return;
	}

	FILE *fp = fopen(FILE_APPID, "w");

	if (!fp)
		return;

	fprintf(fp, "%s\n", PROJECT_ID);
	fclose(fp);

	initialized = SteamAPI_Init();

	if (!initialized)
		return;

	ID = SteamAPI_ISteamUser_GetSteamID(SteamUser());

	sclient = SteamClient();
	spipe   = SteamAPI_ISteamClient_CreateSteamPipe(sclient);
	sutils  = SteamAPI_ISteamClient_GetISteamUtils(sclient, spipe, STEAMUTILS_INTERFACE_VERSION);

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
		leaderboards[i]->update(sutils);
}



/***********************************************************************
     * Steam
     * init

***********************************************************************/
void ach::Steam::init()
{
	if (!initialized)
		return;

	list_foreach(leaderboards)
		leaderboards[i]->init();
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

	if (!name)
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

	if (!name)
		return false;

	bool res;

	if (SteamUserStats()->GetAchievement(name, &res))
		return res;

	return false;
}



/***********************************************************************
     * Steam
     * setHighscore

***********************************************************************/
void ach::Steam::setHighscore(const char *name, unsigned int score)
{
	if (!initialized)
		return;

	if (!name)
		return;

	ach::Leaderboard *lb = getLeaderboard(name);

	if (!lb)
	{
		logger->log(ach::LogLevel::llDebug, "Could not find leaderboard \"%s\"", name);
		return;
	}

	if (!lb->initialized)
	{
		logger->log(ach::LogLevel::llDebug, "Leaderboard \"%s\" is not initialized", name);
		return;
	}

	lb->setHighscore(score);
}



/***********************************************************************
     * Steam
     * getHighscore

***********************************************************************/
unsigned int ach::Steam::getHighscore(const char *name)
{
	if (!initialized)
		return 0;

	if (!name)
		return 0;

	ach::Leaderboard *lb = getLeaderboard(name);

	if (!lb)
		return 0;

	if (!lb->initialized)
		return 0;

	return lb->high;
}



/***********************************************************************
     * Steam
     * getBestscore

***********************************************************************/
unsigned int ach::Steam::getBestscore(const char *name)
{
	if (!initialized)
		return 0;

	if (!name)
		return 0;

	ach::Leaderboard *lb = getLeaderboard(name);

	if (!lb)
		return 0;

	if (!lb->initialized)
		return 0;

	return lb->best;
}



/***********************************************************************
     * Steam
     * getLeaderboard

***********************************************************************/
ach::Leaderboard* ach::Steam::getLeaderboard(const char *name)
{
	if (!name)
		return NULL;

	list_foreach(leaderboards)
		if (strcmp(name, leaderboards[i]->name) == 0)
			return leaderboards[i];

	return NULL;
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
