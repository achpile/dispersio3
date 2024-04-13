#ifndef __CONTAINER_RESOURCES
#define __CONTAINER_RESOURCES


namespace ach
{
	struct Resources
	{
		struct
		{
			sf::Font *base;
		} fonts;

		struct
		{
			sf::Image *icon;
		} meta;


		 Resources();
		~Resources();

		void loadFont (sf::Font **font  , const char *filename);
		void loadImage(sf::Image **image, const char *filename);
	};
}

#endif
