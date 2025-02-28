#ifndef __FRAMEWORK_MATH_ORIENTATION
#define __FRAMEWORK_MATH_ORIENTATION


namespace ach
{
	enum Orientation
	{
		oVertical = 0,
		oHorizontal,
		oCount
	};
}



ach::Orientation operator! (ach::Orientation o);
ach::Orientation orient_get(ach::Line l);

float orient_rect_min (ach::Orientation o, sf::FloatRect r);
float orient_rect_max (ach::Orientation o, sf::FloatRect r);
float orient_rect_size(ach::Orientation o, sf::FloatRect r);

sf::Vector2f orient_v_create(ach::Orientation o);
float        orient_v_coord (ach::Orientation o, sf::Vector2f  v);
void         orient_v_set   (ach::Orientation o, sf::Vector2f *v, float x);

#endif
