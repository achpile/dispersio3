#ifndef __FRAMEWORK_STEAM_LEADERBOARD
#define __FRAMEWORK_STEAM_LEADERBOARD


namespace ach
{
	enum LeaderboardStatus
	{
		lsLoading,
		lsSuccess,
		lsFailed
	};


	enum LeaderboardClass
	{
		lcNearest,
		lcFriends,
		lcBest
	};


	enum LeaderboardCallback
	{
		lbcFindLeaderboard = k_iSteamUserStatsCallbacks + 4,
		lbcDownloadScore   = k_iSteamUserStatsCallbacks + 5,
		lbcUploadScore     = k_iSteamUserStatsCallbacks + 6
	};


	struct Leaderboard
	{
		std::vector<ach::LeaderboardEntry> entries;
		ach::LeaderboardStatus             status;
		SteamLeaderboard_t                 handle;

		SteamAPICall_t hSteamAPICallFind;
		SteamAPICall_t hSteamAPICallDown;
		SteamAPICall_t hSteamAPICallLoad;
		SteamAPICall_t hSteamAPICallHigh;

		unsigned int   highscore;
		unsigned int   rank;

		char           name[STR_LEN_NAME];
		bool           initialized;
		bool           synced;


		 Leaderboard(const char *_name);
		~Leaderboard();

		void update(intptr_t utils);

		void setHighscore(unsigned int score);
		void getHighscore();
		void getLeaderboard(ach::LeaderboardClass lbClass);

		void onFindLeaderboard(LeaderboardFindResult_t       *pResult, bool bIOFailure);
		void onDownloadScore  (LeaderboardScoresDownloaded_t *pResult, bool bIOFailure);
		void onDownloadHigh   (LeaderboardScoresDownloaded_t *pResult, bool bIOFailure);
		void onUploadHiscore  (LeaderboardScoreUploaded_t    *pResult, bool bIOFailure);
	};
}

#endif
