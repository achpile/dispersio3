#ifndef __MAP_CAMERA
#define __MAP_CAMERA


namespace ach
{
	struct Camera
	{
		ach::Phys      *follower;
		ach::Map       *map;

		sf::FloatRect   area;
		sf::FloatRect   viewport;
		sf::View        view;


		 Camera(ach::Map *_map);
		~Camera();

		void update();
		bool check(sf::Vector2f v, bool _area = false);
		bool check(sf::FloatRect r, bool _area = false);

		void follow(ach::Phys *phys);
		void set(ach::MapArea *_area);
		void calc();
	};
}

#endif
