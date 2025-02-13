#ifndef __MAP_CAMERA
#define __MAP_CAMERA


namespace ach
{
	struct Camera
	{
		ach::Phys      *follower;
		ach::Map       *map;

		sf::Vector2i    pos;
		sf::FloatRect   viewport;
		sf::IntRect     tiles;
		sf::View        view;


		 Camera(ach::Map *_map);
		~Camera();

		void update();
		bool check(sf::Vector2f v);
		bool check(sf::FloatRect r);

		void follow(ach::Phys *phys);
		void calc();
	};
}

#endif
