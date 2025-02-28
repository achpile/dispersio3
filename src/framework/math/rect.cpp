#include "meta/headers.hpp"


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
