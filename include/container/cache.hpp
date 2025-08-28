#ifndef __CONTAINER_CACHE
#define __CONTAINER_CACHE


namespace ach
{
	struct Cache
	{
		ach::DataMap *current;

		json_t *campaign;


		 Cache();
		~Cache();

		void init();
		void reset();
		void finish();
	};
}

#endif
