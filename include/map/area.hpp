#ifndef __MAP_AREA
#define __MAP_AREA


namespace ach
{
	struct MapArea
	{
		ach::DataTrack *track;
		sf::FloatRect   rect;

		bool played;


		 MapArea(json_t *obj);
		 MapArea(sf::FloatRect _rect);
		~MapArea();

		bool play();
	};
}

#endif
