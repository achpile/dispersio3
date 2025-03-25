#ifndef __MAP_OBJECT_FRAGILE
#define __MAP_OBJECT_FRAGILE


namespace ach
{
	struct MapObjectFragile : MapObject
	{
		ach::DataSound *sfx;
		ach::Model     *crack;
		ach::Timer      cracking;

		bool cracked;
		bool secret;


		 MapObjectFragile(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectFragile();

		void reset();
		void handle();
		void post();
		void stand(ach::Phys *p);
	};
}

#endif
