#ifndef __FRAMEWORK_ORIENTATION_ORIENTATION
#define __FRAMEWORK_ORIENTATION_ORIENTATION


namespace ach
{
	enum Orientation
	{
		oVertical = 0,
		oHorizontal,
		oCount
	};
}



float orient_rect_min (ach::Orientation o, sf::FloatRect r);
float orient_rect_max (ach::Orientation o, sf::FloatRect r);
float orient_rect_size(ach::Orientation o, sf::FloatRect r);

sf::Vector2f orient_vector(ach::Orientation o);

#endif
