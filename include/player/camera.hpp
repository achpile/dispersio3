#ifndef __PLAYER_CAMERA
#define __PLAYER_CAMERA


namespace ach
{
	struct Camera
	{
		sf::FloatRect   viewport;
		sf::FloatRect   area;
		sf::Vector2f    offset;
		sf::View        view;


		 Camera();
		~Camera();

		void update();
		void check();

		void setArea(sf::FloatRect _area);
	};
}

#endif
