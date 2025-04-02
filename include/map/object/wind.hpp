#ifndef __MAP_OBJECT_WIND
#define __MAP_OBJECT_WIND


namespace ach
{
	struct MapObjectWind : MapObject
	{
		ach::Direction dir;
		sf::Vector2f   stream;

		float speed;


		 MapObjectWind(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectWind();

		void touch();
		void post();
	};
}

#endif
