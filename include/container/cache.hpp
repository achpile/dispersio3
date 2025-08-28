#ifndef __CONTAINER_CACHE
#define __CONTAINER_CACHE


namespace ach
{
	struct Cache
	{
		ach::DataMap *current;

		json_t *campaign;
		json_t *cache;


		 Cache();
		~Cache();

		void init();
		void save();
		void reset();
		void finish();
	};
}

#endif
