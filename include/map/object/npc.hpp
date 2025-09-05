#ifndef __MAP_OBJECT_NPC
#define __MAP_OBJECT_NPC


namespace ach
{
	struct MapObjectNPC : MapObject
	{
		ach::DataNPC   *base;
		ach::Direction  face;
		ach::Timer      wait;

		sf::Vector2f    spawn;

		bool  walking;

		float dest;
		float min;
		float max;


		 MapObjectNPC(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectNPC();

		void reset();
		void handle();
		void touch();

		void move();
		void stop();
	};
}

#endif
