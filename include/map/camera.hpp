#ifndef __MAP_CAMERA
#define __MAP_CAMERA


namespace ach
{
	struct Camera
	{
		ach::Phys      *follower;

		sf::FloatRect   viewport;
		sf::FloatRect   area;
		sf::View        view;


		 Camera();
		~Camera();

		void update();
		void check();
		void center();

		void follow(ach::Phys *phys);
		void setArea(sf::FloatRect _area);
	};
}

#endif
