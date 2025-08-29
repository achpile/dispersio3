#ifndef __CONTAINER_CACHE
#define __CONTAINER_CACHE


namespace ach
{
	enum GameMode
	{
		gmNormal,
		gmHard
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
		void finish();

		void select(const char *map);
		int  spawn();

		void die();
		void collect(int id);
		void checkpoint(int id);
	};
}

#endif
