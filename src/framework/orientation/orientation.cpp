#include "meta/headers.hpp"


/***********************************************************************
     * orient_rect_min

***********************************************************************/
float orient_rect_min(ach::Orientation o, sf::FloatRect r)
{
	switch (o)
	{
		case ach::Orientation::oVertical   : return r.top;
		case ach::Orientation::oHorizontal : return r.left;
		case ach::Orientation::oCount      : return 0.0f;
	}

	return 0.0f;
}



/***********************************************************************
     * orient_rect_max

***********************************************************************/
float orient_rect_max(ach::Orientation o, sf::FloatRect r)
{
	switch (o)
	{
		case ach::Orientation::oVertical   : return r.top  + r.height;
		case ach::Orientation::oHorizontal : return r.left + r.width;
		case ach::Orientation::oCount      : return 0.0f;
	}

	return 0.0f;
}



/***********************************************************************
     * orient_rect_size

***********************************************************************/
float orient_rect_size(ach::Orientation o, sf::FloatRect r)
{
	switch (o)
	{
		case ach::Orientation::oVertical   : return r.height;
		case ach::Orientation::oHorizontal : return r.width;
		case ach::Orientation::oCount      : return 0.0f;
	}

	return 0.0f;
}



/***********************************************************************
     * orient_vector

***********************************************************************/
sf::Vector2f orient_vector(ach::Orientation o)
{
	switch (o)
	{
		case ach::Orientation::oVertical   : return sf::Vector2f(0.0f, 1.0f);
		case ach::Orientation::oHorizontal : return sf::Vector2f(1.0f, 0.0f);
		case ach::Orientation::oCount      : return sf::Vector2f(0.0f, 0.0f);
	}

	return sf::Vector2f(0.0f, 0.0f);
}



/***********************************************************************
     * orient_coord

***********************************************************************/
float orient_coord(ach::Orientation o, sf::Vector2f v)
{
	switch (o)
	{
		case ach::Orientation::oVertical   : return v.y;
		case ach::Orientation::oHorizontal : return v.x;
		case ach::Orientation::oCount      : return 0.0f;
	}

	return 0.0f;
}
