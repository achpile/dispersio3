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


	struct Cache
	{
		ach::DataMap   *current;
		ach::LevelMode  mode;

		json_t *campaign;
		json_t *cache;
		json_t *info;

		bool    def;
		bool    hard;
		int     deaths;
		float   playtime;


		 Cache();
		~Cache();

		void init();
		void update();
		void save();
		void store();
		void reset(bool _hard);

		void select(const char *map, ach::LevelMode _mode);
		void revert();
		int  spawn();

		/*  check.cpp  */
		bool isRevert();
		bool isBeaten(const char *level);
		bool isPossible(ach::LevelMode _mode);
		bool isPossibleDream();

		/*  store.cpp  */
		void goal();
		void die();
		void collect(int id);
		void checkpoint(int id);

		/*  stats.cpp  */
		sf::String getPlaytime();
		sf::String getDeaths();
		sf::String getCollected();
		sf::String getItems();
		sf::String getItems(const char *name);

		sf::String getError(ach::LevelMode _mode);
		sf::String getErrorDream();

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
