#include "meta/headers.hpp"


/***********************************************************************
     * rect_pos

***********************************************************************/
sf::Vector2f rect_pos(sf::FloatRect r)
{
	return rect_lt(r);
}



/***********************************************************************
     * rect_size

***********************************************************************/
sf::Vector2f rect_size(sf::FloatRect r)
{
	return sf::Vector2f(r.width, r.height);
}



/***********************************************************************
     * rect_center

***********************************************************************/
sf::Vector2f rect_center(sf::FloatRect r)
{
	return sf::Vector2f(r.left + r.width / 2.0f, r.top + r.height / 2.0f);
}



/***********************************************************************
     * rect_place

***********************************************************************/
sf::Vector2f rect_place(sf::FloatRect r, sf::FloatRect p)
{
	return sf::Vector2f(r.left + r.width / 2.0f, r.top + r.height - p.height / 2.0f);
}



/***********************************************************************
     * rect_lt

***********************************************************************/
sf::Vector2f rect_lt(sf::FloatRect r)
{
	return sf::Vector2f(r.left, r.top);
}



/***********************************************************************
     * rect_rt

***********************************************************************/
sf::Vector2f rect_rt(sf::FloatRect r)
{
	return sf::Vector2f(r.left + r.width, r.top);
}



/***********************************************************************
     * rect_lb

***********************************************************************/
sf::Vector2f rect_lb(sf::FloatRect r)
{
	return sf::Vector2f(r.left, r.top + r.height);
}



/***********************************************************************
     * rect_rb

***********************************************************************/
sf::Vector2f rect_rb(sf::FloatRect r)
{
	return sf::Vector2f(r.left + r.width, r.top + r.height);
}



/***********************************************************************
     * rect_value

***********************************************************************/
float rect_value(sf::FloatRect r, ach::Direction d)
{
	switch (d)
	{
		case ach::Direction::dUp   : return r.top;
		case ach::Direction::dDown : return r.top + r.height;
		case ach::Direction::dLeft : return r.left;
		case ach::Direction::dRight: return r.left + r.width;
		case ach::Direction::dCount: return 0.0f;
	}

	return 0.0f;
}



/***********************************************************************
     * rect_line

***********************************************************************/
ach::Line rect_line(sf::FloatRect r, ach::Direction d)
{
	ach::Line l;

	switch (d)
	{
		case ach::Direction::dUp:
			l.a = rect_lt(r);
			l.b = rect_rt(r);
			break;

		case ach::Direction::dDown:
			l.a = rect_lb(r);
			l.b = rect_rb(r);
			break;

		case ach::Direction::dLeft:
			l.a = rect_lt(r);
			l.b = rect_lb(r);
			break;

		case ach::Direction::dRight:
			l.a = rect_rt(r);
			l.b = rect_rb(r);
			break;

		case ach::Direction::dCount:
			break;
	}

	l.calc();

	return l;
}
