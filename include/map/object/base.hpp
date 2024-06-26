#ifndef __MAP_OBJECT_BASE
#define __MAP_OBJECT_BASE


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
