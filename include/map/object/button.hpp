#ifndef __MAP_OBJECT_BUTTON
#define __MAP_OBJECT_BUTTON


namespace ach
{
	struct MapObjectButton : MapObject
	{
		ach::Boss      *boss;
		ach::DataSound *sfx;

		int  link;
		bool active;
		bool pressed;


		 MapObjectButton(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectButton();

		void init(ach::Map *map);
		void touch();

		void animate();
	};
}

#endif
