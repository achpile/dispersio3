#include "meta/headers.hpp"


/***********************************************************************
     * Leaderboard
     * constructor

***********************************************************************/
ach::Leaderboard::Leaderboard(const char *_name, bool _time)
{
	strncpy(name, _name, STR_LEN_NAME);

	status            = ach::LeaderboardStatus::lsFailed;
	initialized       = false;
	synced            = false;
	time              = _time;
	handle            = 0;
	high              = 0;
	best              = 0;
	rank              = 0;
	hSteamAPICallDown = 0;
	hSteamAPICallHigh = 0;
	hSteamAPICallBest = 0;
	hSteamAPICallLoad = 0;
	hSteamAPICallFind = 0;
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
     * init

***********************************************************************/
void ach::Leaderboard::init()
{
	hSteamAPICallFind = SteamAPI_ISteamUserStats_FindLeaderboard(SteamUserStats(), name);
}



/***********************************************************************
     * Leaderboard
     * update

***********************************************************************/
void ach::Leaderboard::update(ISteamUtils *utils)
{
	bool ioError;

	if (hSteamAPICallFind)
	{
		if (SteamAPI_ISteamUtils_IsAPICallCompleted(utils, hSteamAPICallFind, &ioError))
		{
			if (!ioError)
			{
				LeaderboardFindResult_t res;

				SteamAPI_ISteamUtils_GetAPICallResult(utils, hSteamAPICallFind, &res, sizeof(res), ach::LeaderboardCallback::lbcFindLeaderboard, &ioError);
				onFindLeaderboard(&res, ioError);
			}

			hSteamAPICallFind = 0;
		}
	}


	if (hSteamAPICallDown)
	{
		if (SteamAPI_ISteamUtils_IsAPICallCompleted(utils, hSteamAPICallDown, &ioError))
		{
			status = ach::LeaderboardStatus::lsFailed;

			if (!ioError)
			{
				LeaderboardScoresDownloaded_t res;

				SteamAPI_ISteamUtils_GetAPICallResult(utils, hSteamAPICallDown, &res, sizeof(res), ach::LeaderboardCallback::lbcDownloadScore, &ioError);
				onDownloadScore(&res, ioError);
			}

			hSteamAPICallDown = 0;
		}
	}


	if (hSteamAPICallHigh)
	{
		if (SteamAPI_ISteamUtils_IsAPICallCompleted(utils, hSteamAPICallHigh, &ioError))
		{
			if (!ioError)
			{
				LeaderboardScoresDownloaded_t res;

				SteamAPI_ISteamUtils_GetAPICallResult(utils, hSteamAPICallHigh, &res, sizeof(res), ach::LeaderboardCallback::lbcDownloadScore, &ioError);
				onDownloadHigh(&res, ioError);
			}

			hSteamAPICallHigh = 0;
		}
	}


	if (hSteamAPICallBest)
	{
		if (SteamAPI_ISteamUtils_IsAPICallCompleted(utils, hSteamAPICallBest, &ioError))
		{
			if (!ioError)
			{
				LeaderboardScoresDownloaded_t res;

				SteamAPI_ISteamUtils_GetAPICallResult(utils, hSteamAPICallBest, &res, sizeof(res), ach::LeaderboardCallback::lbcDownloadScore, &ioError);
				onDownloadBest(&res, ioError);
			}

			hSteamAPICallBest = 0;
		}
	}


	if (hSteamAPICallLoad)
	{
		if (SteamAPI_ISteamUtils_IsAPICallCompleted(utils, hSteamAPICallLoad, &ioError))
		{
			if (!ioError)
			{
				LeaderboardScoreUploaded_t res;

				SteamAPI_ISteamUtils_GetAPICallResult(utils, hSteamAPICallLoad, &res, sizeof(res), ach::LeaderboardCallback::lbcUploadScore, &ioError);
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

	hSteamAPICallLoad = SteamAPI_ISteamUserStats_UploadLeaderboardScore(SteamUserStats(), handle, k_ELeaderboardUploadScoreMethodKeepBest, score, NULL, 0);
}



/***********************************************************************
     * Leaderboard
     * getLeaderboard

***********************************************************************/
void ach::Leaderboard::getLeaderboard(ach::LeaderboardClass lbClass)
{
	if (!handle)
		return;

	status = ach::LeaderboardStatus::lsLoading;

	ELeaderboardDataRequest req;

	int start;
	int end;

	switch (lbClass) {
		case ach::LeaderboardClass::lcNearest: req = k_ELeaderboardDataRequestGlobalAroundUser; start = -4; end = 5; break;
		case ach::LeaderboardClass::lcFriends: req = k_ELeaderboardDataRequestFriends         ; start = -4; end = 5; break;
		case ach::LeaderboardClass::lcBest   : req = k_ELeaderboardDataRequestGlobal          ; start =  1; end = 9; break;
	}

	entries.clear();

	hSteamAPICallDown = SteamAPI_ISteamUserStats_DownloadLeaderboardEntries(SteamUserStats(), handle, req, start, end);
}



/***********************************************************************
     * Leaderboard
     * getHighscore

***********************************************************************/
void ach::Leaderboard::getHighscore()
{
	if (!handle)
		return;

	hSteamAPICallHigh = SteamAPI_ISteamUserStats_DownloadLeaderboardEntries(SteamUserStats(), handle, k_ELeaderboardDataRequestGlobalAroundUser, 1, 1);
}



/***********************************************************************
     * Leaderboard
     * getBestscore

***********************************************************************/
void ach::Leaderboard::getBestscore()
{
	if (!handle)
		return;

	hSteamAPICallBest = SteamAPI_ISteamUserStats_DownloadLeaderboardEntries(SteamUserStats(), handle, k_ELeaderboardDataRequestGlobal, 1, 1);
}



/***********************************************************************
     * Leaderboard
     * onFindLeaderboard

***********************************************************************/
void ach::Leaderboard::onFindLeaderboard(LeaderboardFindResult_t *pCallback, bool bIOFailure)
{
	if (!pCallback->m_bLeaderboardFound || bIOFailure)
	{
		logger->log(ach::LogLevel::llWarning, "Failed finding leaderboard \"%s\"", name);
		return;
	}

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
		status = ach::LeaderboardStatus::lsFailed;
		logger->log(ach::LogLevel::llWarning, "Failed getting leaderboard for \"%s\"", name);
		return;
	}

	LeaderboardEntry_t data;

	int count = std::min(pCallback->m_cEntryCount, 9);

	for (int i = 0; i < count; i++)
	{
		SteamUserStats()->GetDownloadedLeaderboardEntry(pCallback->m_hSteamLeaderboardEntries, i, &data, NULL, 0);
		entries.push_back(ach::LeaderboardEntry(data.m_nGlobalRank, data.m_nScore, time, data.m_steamIDUser));
	}

	if (entries.size()) status = ach::LeaderboardStatus::lsSuccess;
	else                status = ach::LeaderboardStatus::lsNoData;

	getHighscore();
}



/***********************************************************************
     * Leaderboard
     * onDownloadHigh

***********************************************************************/
void ach::Leaderboard::onDownloadHigh(LeaderboardScoresDownloaded_t *pCallback, bool bIOFailure)
{
	if (bIOFailure)
	{
		logger->log(ach::LogLevel::llWarning, "Failed getting highscore for \"%s\"", name);
		return;
	}

	if (pCallback->m_cEntryCount >= 1)
	{
		LeaderboardEntry_t data;
		SteamUserStats()->GetDownloadedLeaderboardEntry(pCallback->m_hSteamLeaderboardEntries, 0, &data, NULL, 0);

		high = data.m_nScore;
		rank = data.m_nGlobalRank;
	}

	getBestscore();
}



/***********************************************************************
     * Leaderboard
     * onDownloadBest

***********************************************************************/
void ach::Leaderboard::onDownloadBest(LeaderboardScoresDownloaded_t *pCallback, bool bIOFailure)
{
	if (bIOFailure)
	{
		logger->log(ach::LogLevel::llWarning, "Failed getting bestscore for \"%s\"", name);
		return;
	}

	initialized = true;

	if (pCallback->m_cEntryCount >= 1)
	{
		LeaderboardEntry_t data;
		SteamUserStats()->GetDownloadedLeaderboardEntry(pCallback->m_hSteamLeaderboardEntries, 0, &data, NULL, 0);

		best = data.m_nScore;
	}
}



/***********************************************************************
     * Leaderboard
     * onUploadHiscore

***********************************************************************/
void ach::Leaderboard::onUploadHiscore(LeaderboardScoreUploaded_t *pCallback, bool bIOFailure)
{
	if (!pCallback->m_bSuccess || bIOFailure)
	{
		logger->log(ach::LogLevel::llWarning, "Failed uploading highscore for \"%s\"", name);
		return;
	}

	rank = pCallback->m_nGlobalRankNew;

	getHighscore();
}
