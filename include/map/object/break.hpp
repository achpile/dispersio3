#ifndef __MAP_OBJECT_BREAK
#define __MAP_OBJECT_BREAK


namespace ach
{
	struct MapObjectBreak : MapObject
	{
		ach::DataSound *sfx;
		ach::Model     *crack;
		ach::Timer      cracking;

		bool cracked;
		bool secret;


		 MapObjectBreak(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectBreak();

		void reset();
		void handle();
		void post();
		void hit();
	};
}

#endif
