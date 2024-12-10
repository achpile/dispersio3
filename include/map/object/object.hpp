#ifndef __MAP_OBJECT_OBJECT
#define __MAP_OBJECT_OBJECT


namespace ach
{
	struct MapObject
	{
		ach::ProcessWorld *world;
		ach::Model        *model;
		ach::Phys          phys;

		bool alive;


		         MapObject(ach::ProcessWorld *_world, json_t *obj);
		virtual ~MapObject();

		bool update();
		void render();

		virtual void touch() {};
		virtual void use()   {};
	};
}

#endif
