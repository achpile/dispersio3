#include "meta/headers.hpp"


/***********************************************************************
     * Leaderboard
     * constructor

***********************************************************************/
ach::Leaderboard::Leaderboard(const char *_name)
{
	strncpy(name, _name, STR_LEN_NAME);

	status            = lsFailed;
	initialized       = false;
	synced            = false;
	handle            = 0;
	highscore         = 0;
	rank              = 0;
	hSteamAPICallDown = 0;
	hSteamAPICallHigh = 0;
	hSteamAPICallLoad = 0;

	hSteamAPICallFind = SteamAPI_ISteamUserStats_FindLeaderboard((intptr_t)SteamUserStats(), name);
}



/***********************************************************************
     * Leaderboard
     * destructor

***********************************************************************/
ach::Leaderboard::~Leaderboard()
{
}



/***********************************************************************
     * Leaderboard
     * update

***********************************************************************/
void ach::Leaderboard::update(intptr_t utils)
{
	bool ioError;

	if (hSteamAPICallFind)
	{
		if (SteamAPI_ISteamUtils_IsAPICallCompleted(utils, hSteamAPICallFind, &ioError))
		{
			if (!ioError)
			{
				LeaderboardFindResult_t res;

				SteamAPI_ISteamUtils_GetAPICallResult(utils, hSteamAPICallFind, &res, sizeof(res), lbcFindLeaderboard, &ioError);
				onFindLeaderboard(&res, ioError);
			}

			hSteamAPICallFind = 0;
		}
	}


	if (hSteamAPICallDown)
	{
		if (SteamAPI_ISteamUtils_IsAPICallCompleted(utils, hSteamAPICallDown, &ioError))
		{
			status = lsFailed;

			if (!ioError)
			{
				LeaderboardScoresDownloaded_t res;

				SteamAPI_ISteamUtils_GetAPICallResult(utils, hSteamAPICallDown, &res, sizeof(res), lbcDownloadScore, &ioError);
				onDownloadScore(&res, ioError);
			}

			hSteamAPICallDown = 0;
		}
	}


	if (hSteamAPICallHigh)
	{
		if (SteamAPI_ISteamUtils_IsAPICallCompleted(utils, hSteamAPICallHigh, &ioError))
		{
			status = lsFailed;

			if (!ioError)
			{
				LeaderboardScoresDownloaded_t res;

				SteamAPI_ISteamUtils_GetAPICallResult(utils, hSteamAPICallHigh, &res, sizeof(res), lbcDownloadScore, &ioError);
				onDownloadHigh(&res, ioError);
			}

			hSteamAPICallHigh = 0;
		}
	}


	if (hSteamAPICallLoad)
	{
		if (SteamAPI_ISteamUtils_IsAPICallCompleted(utils, hSteamAPICallLoad, &ioError))
		{
			if (!ioError)
			{
				LeaderboardScoreUploaded_t res;

				SteamAPI_ISteamUtils_GetAPICallResult(utils, hSteamAPICallLoad, &res, sizeof(res), lbcUploadScore, &ioError);
				onUploadHiscore(&res, ioError);
			}

			hSteamAPICallLoad = 0;
		}
	}
}



/***********************************************************************
     * Leaderboard
     * setHighscore

***********************************************************************/
void ach::Leaderboard::setHighscore(unsigned int score)
{
	if (!handle)
		return;

	rank = 0;

	hSteamAPICallLoad = SteamAPI_ISteamUserStats_UploadLeaderboardScore((intptr_t)SteamUserStats(), handle, k_ELeaderboardUploadScoreMethodKeepBest, score, NULL, 0);
}



/***********************************************************************
     * Leaderboard
     * getLeaderboard

***********************************************************************/
void ach::Leaderboard::getLeaderboard(ach::LeaderboardClass lbClass)
{
	if (!handle)
		return;

	status = lsLoading;

	ELeaderboardDataRequest req;

	int start;
	int end;

	switch (lbClass) {
		case lcNearest: req = k_ELeaderboardDataRequestGlobalAroundUser; start = -4; end = 5; break;
		case lcFriends: req = k_ELeaderboardDataRequestFriends         ; start = -4; end = 5; break;
		case lcBest   : req = k_ELeaderboardDataRequestGlobal          ; start =  1; end = 9; break;
	}

	entries.clear();

	hSteamAPICallDown = SteamAPI_ISteamUserStats_DownloadLeaderboardEntries((intptr_t)SteamUserStats(), handle, req, start, end);
}



/***********************************************************************
     * Leaderboard
     * getHighscore

***********************************************************************/
void ach::Leaderboard::getHighscore()
{
	if (!handle)
		return;

	status            = lsLoading;
	highscore         = 0;
	hSteamAPICallHigh = SteamAPI_ISteamUserStats_DownloadLeaderboardEntries((intptr_t)SteamUserStats(), handle, k_ELeaderboardDataRequestGlobal, 1, 1);
}



/***********************************************************************
     * Leaderboard
     * onFindLeaderboard

***********************************************************************/
void ach::Leaderboard::onFindLeaderboard(LeaderboardFindResult_t *pCallback, bool bIOFailure)
{
	if (!pCallback->m_bLeaderboardFound || bIOFailure)
		return;

	handle = pCallback->m_hSteamLeaderboard;

	getHighscore();
}



/***********************************************************************
     * Leaderboard
     * onDownloadScore

***********************************************************************/
void ach::Leaderboard::onDownloadScore(LeaderboardScoresDownloaded_t *pCallback, bool bIOFailure)
{
	if (bIOFailure)
	{
		status = lsFailed;
		return;
	}

	LeaderboardEntry_t data;

	status = lsSuccess;

	int count = std::min(pCallback->m_cEntryCount, 9);

	for (int i = 0; i < count; i++)
	{
		SteamUserStats()->GetDownloadedLeaderboardEntry(pCallback->m_hSteamLeaderboardEntries, i, &data, NULL, 0);
		entries.push_back(ach::LeaderboardEntry(data.m_nGlobalRank, data.m_nScore, data.m_steamIDUser));
	}
}



/***********************************************************************
     * Leaderboard
     * onDownloadHigh

***********************************************************************/
void ach::Leaderboard::onDownloadHigh(LeaderboardScoresDownloaded_t *pCallback, bool bIOFailure)
{
	if (bIOFailure)
	{
		status = lsFailed;
		return;
	}

	if (pCallback->m_cEntryCount < 1)
	{
		status = lsFailed;
		return;
	}

	LeaderboardEntry_t data;
	SteamUserStats()->GetDownloadedLeaderboardEntry(pCallback->m_hSteamLeaderboardEntries, 0, &data, NULL, 0);

	initialized = true;
	status      = lsSuccess;
	highscore   = data.m_nScore;
}



/***********************************************************************
     * Leaderboard
     * onUploadHiscore

***********************************************************************/
void ach::Leaderboard::onUploadHiscore(LeaderboardScoreUploaded_t *pCallback, bool bIOFailure)
{
	if (!pCallback->m_bSuccess || bIOFailure)
		return;

	rank = pCallback->m_nGlobalRankNew;

	getHighscore();
}
