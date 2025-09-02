#ifndef __CACHE_CACHE
#define __CACHE_CACHE


namespace ach
{
	enum GameMode
	{
		gmNormal,
		gmHard
	};


	enum LevelList
	{
		llDream,
		llReplay,
		llNavigation,
		llTraining
	};


	struct Cache
	{
		ach::DataMap  *current;
		ach::GameMode  mode;

		json_t *campaign;
		json_t *cache;
		json_t *info;

		bool    def;
		int     deaths;
		float   playtime;


		 Cache();
		~Cache();

		void init();
		void update();
		void save();
		void store();
		void reset(const char *_mode);

		void select(const char *map);
		int  spawn();

		/*  check.cpp  */
		bool isReturn();
		bool isBeaten(const char *level);

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

		/*  list.cpp  */
		json_t* listLevels(ach::LevelList list);
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
