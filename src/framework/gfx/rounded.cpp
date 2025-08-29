#include "meta/headers.hpp"


/***********************************************************************
     * RoundedRectangle
     * constructor

***********************************************************************/
ach::RoundedRectangle::RoundedRectangle(sf::Vector2f _size)
{
	radius = 5;
	count  = 5;

	setSize(_size);
}



/***********************************************************************
     * RoundedRectangle
     * destructor

***********************************************************************/
ach::RoundedRectangle::~RoundedRectangle()
{
}



/***********************************************************************
     * RoundedRectangle
     * setSize

***********************************************************************/
void ach::RoundedRectangle::setSize(sf::Vector2f _size)
{
	size = _size;

	update();
}



/***********************************************************************
     * RoundedRectangle
     * getPointCount

***********************************************************************/
std::size_t ach::RoundedRectangle::getPointCount() const
{
	return count * 4;
}



/***********************************************************************
     * RoundedRectangle
     * getPoint

***********************************************************************/
sf::Vector2f ach::RoundedRectangle::getPoint(std::size_t index) const
{
	if (index >= getPointCount())
		return sf::Vector2f(0,0);

	sf::Vector2f c;

	float d = 90.0f / (count - 1);
	int   i = index /  count;

	switch(i) {
		case 0: c.x = size.x - radius; c.y = radius         ; break;
		case 1: c.x = radius         ; c.y = radius         ; break;
		case 2: c.x = radius         ; c.y = size.y - radius; break;
		case 3: c.x = size.x - radius; c.y = size.y - radius; break;
	}

	return sf::Vector2f( radius * cos(d * (index - i) * MATH_RAD) + c.x,
                        -radius * sin(d * (index - i) * MATH_RAD) + c.y);
}
