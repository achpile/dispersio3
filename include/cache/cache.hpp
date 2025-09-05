#ifndef __CACHE_CACHE
#define __CACHE_CACHE


namespace ach
{
	enum LevelMode
	{
		lmDream,
		lmReplay,
		lmNavigation,
		lmTraining
	};


	enum LevelState
	{
		lsIntro,
		lsLevel,
		lsOutro
	};


	struct Cache
	{
		ach::DataMap    *current;
		ach::LevelMode   mode;
		ach::LevelState  state;

		json_t *campaign;
		json_t *cache;
		json_t *info;

		bool    hard;
		bool    finished;
		int     deaths;
		float   playtime;


		 Cache();
		~Cache();

		void update();
		void init();
		void save();
		void reset(bool _hard);
		int  spawn();

		/*  check.cpp  */
		bool isDefault();
		bool isBeaten(const char *level);
		bool isRevert();
		bool isCutscenes(ach::LevelMode _mode);
		bool isPossible(ach::LevelMode _mode);
		bool isPossibleDream();

		/*  state.cpp  */
		void goal();
		void cutscene();
		void revert();
		void finish();
		void warp(const char *map, ach::LevelMode _mode, bool intro);
		void pick(const char *map, ach::LevelMode _mode, bool intro);

		/*  store.cpp  */
		void die();
		void collect(int id);
		void checkpoint(int id);
		void beat(const char *map);

		const char* getError(ach::LevelMode _mode);
		const char* getErrorDream();

		/*  stats.cpp  */
		sf::String getPlaytime();
		sf::String getDeaths();
		sf::String getCollected();
		sf::String getItems();
		sf::String getItems(const char *name);

		/*  list.cpp  */
		json_t* listLevels(ach::LevelMode list);
		void    listLevelsDream     (json_t *list);
		void    listLevelsReplay    (json_t *list);
		void    listLevelsNavigation(json_t *list);
		void    listLevelsTraining  (json_t *list);

		/*  flag.cpp  */
		bool getFlag(const char *name);
		void setFlag(const char *name);
	};
}

#endif
