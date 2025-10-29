#ifndef __CONTAINER_RECORDS
#define __CONTAINER_RECORDS


namespace ach
{
	enum Achievement
	{
		acMilitaryBase = 0,
		acLaunchPad,
		acCave,
		acLab,
		acForest,
		acFactory,
		acTemple,
		acDuck,
		acIsland,
		acPlumber,
		acRobot,
		acMattress,
		acTimeMachine,
		acDonation,
		acEasy,
		acNormal,
		acHard,
		acCollectGames,
		acCollectFresh,
		acCollectAll,
		acBrickOut,
		acHexagon,
		acRace,
		acSnake,
		acSimon,
		acTetris,

		acCount
	};


	struct Records
	{
		json_t *data;

		json_t *achievements;
		json_t *highscores;
		json_t *leaderboards;

		bool    synced;


		 Records();
		~Records();

		void save();
		void init();
		void sync();

		void syncAchievement(ach::Achievement achievement);
		bool syncLeaderboard(const char *name);
		bool syncHighscore  (ach::ArcadeGame game);

		void setAchievement(ach::Achievement achievement);
		void setHighscore  (ach::ArcadeGame game, int score);
		void setLeaderboard(const char *name, float time);

		bool  getAchievement(ach::Achievement achievement);
		int   getHighscore  (ach::ArcadeGame game);
		float getLeaderboard(const char *name);
	};
}

#endif
