#include "meta/headers.hpp"


/***********************************************************************
     * projection_vector

***********************************************************************/
float projection_vector(sf::Vector2f a, bool vertical)
{
	return (vertical) ? a.y : a.x;
}



/***********************************************************************
     * projection_rect_pos

***********************************************************************/
float projection_rect_pos(sf::FloatRect rect, bool vertical)
{
	return (vertical) ? rect.top : rect.left;
}



/***********************************************************************
     * projection_rect_len

***********************************************************************/
float projection_rect_len(sf::FloatRect rect, bool vertical)
{
	return (vertical) ? rect.height : rect.width;
}



/***********************************************************************
     * projection_rect_tip

***********************************************************************/
float projection_rect_tip(sf::FloatRect rect, bool vertical)
{
	return (vertical) ? (rect.top + rect.height) : (rect.left + rect.width);
}

