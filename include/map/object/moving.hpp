#ifndef __MAP_OBJECT_MOVING
#define __MAP_OBJECT_MOVING


namespace ach
{
	struct MapObjectMoving : MapObject
	{
		ach::Orientation orient;
		sf::Vector2f     spawn;

		float speed;
		float min;
		float max;


		 MapObjectMoving(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectMoving();

		void reset();
		void handle();
	};
}

#endif
