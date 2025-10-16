#ifndef __CONTAINER_RECORDS
#define __CONTAINER_RECORDS


namespace ach
{
	struct Records
	{
		json_t *data;

		json_t *achievements;
		json_t *highscores;
		json_t *leaderboards;

		 Records();
		~Records();

		void save();

		void setAchievement(const char *name);
		void setHighscore  (const char *name, int score);
		void setLeaderboard(const char *name, float time);

		bool  getAchievement(const char *name);
		int   getHighscore  (const char *name);
		float getLeaderboard(const char *name);
	};
}

#endif
