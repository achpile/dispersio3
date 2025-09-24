#ifndef __MAP_AREA
#define __MAP_AREA


namespace ach
{
	struct MapArea
	{
		ach::DataTrack *track;
		sf::FloatRect   rect;


		 MapArea(json_t *obj);
		 MapArea(sf::FloatRect _rect);
		~MapArea();
	};
}

#endif
