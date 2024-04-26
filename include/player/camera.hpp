#ifndef __PLAYER_CAMERA
#define __PLAYER_CAMERA


namespace ach
{
	struct Camera
	{
		sf::FloatRect   viewport;
		sf::Vector2f    offset;
		sf::View        view;


		 Camera();
		~Camera();

		void update();
	};
}

#endif
