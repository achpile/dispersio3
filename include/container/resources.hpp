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


		 Resources();
		~Resources();

		void loadFont(sf::Font **font, const char *filename);
	};
}

#endif
