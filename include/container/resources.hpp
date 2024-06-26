#ifndef __CONTAINER_RESOURCES
#define __CONTAINER_RESOURCES


namespace ach
{
	struct Resources
	{
		struct
		{
			sf::Font *menu;
			sf::Font *credits;
		} fonts;

		struct
		{
			sf::SoundBuffer *back;
			sf::SoundBuffer *blip;
			sf::SoundBuffer *pick;
		} sound;

		struct
		{
			sf::Image *icon;
		} meta;


		 Resources();
		~Resources();
	};
}

#endif
