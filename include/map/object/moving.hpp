#ifndef __MAP_OBJECT_MOVING
#define __MAP_OBJECT_MOVING


namespace ach
{
	struct MapObjectMoving : MapObject
	{
		std::vector<ach::Phys*> linked;

		ach::Orientation        orient;
		sf::Vector2f            spawn;
		sf::Vector2f            move;

		float speed;
		float min;
		float max;


		 MapObjectMoving(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectMoving();

		void reset();
		void handle();
		void stand(ach::Phys *p);
	};
}

#endif
