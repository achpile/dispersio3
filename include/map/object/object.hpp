#ifndef __MAP_OBJECT_OBJECT
#define __MAP_OBJECT_OBJECT


namespace ach
{
	struct MapObject
	{
		ach::Model *model;
		ach::Phys   phys;

		bool alive;


		 MapObject(json_t *obj);
		~MapObject();

		bool update();
		void render();
	};
}

#endif
