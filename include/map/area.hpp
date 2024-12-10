#ifndef __MAP_AREA
#define __MAP_AREA


namespace ach
{
	struct MapArea
	{
		sf::FloatRect rect;

		 MapArea(json_t *obj);
		 MapArea(sf::FloatRect _rect);
		~MapArea();
	};
}

#endif
