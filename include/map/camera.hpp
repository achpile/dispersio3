#ifndef __MAP_CAMERA
#define __MAP_CAMERA


namespace ach
{
	struct Camera
	{
		ach::Phys      *follower;
		ach::Map       *map;

		sf::FloatRect   viewport;
		sf::FloatRect   area;
		sf::View        view;


		 Camera(ach::Map *_map);
		~Camera();

		void update();
		bool check();

		void follow(ach::Phys *phys);
		void set(ach::MapArea *_area);
	};
}

#endif
