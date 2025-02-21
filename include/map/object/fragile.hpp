#ifndef __MAP_OBJECT_FRAGILE
#define __MAP_OBJECT_FRAGILE


namespace ach
{
	struct MapObjectFragile : MapObject
	{
		ach::Timer cracking;

		bool cracked;


		 MapObjectFragile(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectFragile();

		void reset();
		void handle();
		void stand(ach::Phys *p);
	};
}

#endif
