#ifndef __MAP_OBJECT_YOKU
#define __MAP_OBJECT_YOKU


namespace ach
{
	struct MapObjectYoku : MapObject
	{
		ach::DataSound   *sfx;
		ach::Framer       timer;
		ach::Orientation  pushing;

		float duration;
		float cooldown;
		float offset;


		 MapObjectYoku(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectYoku();

		void reset();
		void handle();

		void state();
		void push(ach::Phys *character);
	};
}

#endif
