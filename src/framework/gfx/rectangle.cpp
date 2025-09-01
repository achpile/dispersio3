#include "meta/headers.hpp"


/***********************************************************************
     * RectangleShape
     * constructor

***********************************************************************/
ach::RectangleShape::RectangleShape(sf::Vector2f _size)
{
	size = _size;

	setRound(false);
}



/***********************************************************************
     * RectangleShape
     * destructor

***********************************************************************/
ach::RectangleShape::~RectangleShape()
{
}



/***********************************************************************
     * RectangleShape
     * style

***********************************************************************/
void ach::RectangleShape::style(ach::MenuTheme *theme)
{
	setFillColor(theme->bg);
	setOutlineColor(theme->border);
	setRound(theme->round);
}



/***********************************************************************
     * RectangleShape
     * setSize

***********************************************************************/
void ach::RectangleShape::setSize(sf::Vector2f _size)
{
	size = _size;

	update();
}



/***********************************************************************
     * RectangleShape
     * setRound

***********************************************************************/
void ach::RectangleShape::setRound(bool round)
{
	if (round) init(5, 5.0f);
	else       init(1, 0.0f);
}



/***********************************************************************
     * RectangleShape
     * init

***********************************************************************/
void ach::RectangleShape::init(int _count, float _radius)
{
	count  = _count;
	radius = _radius;

	update();
}



/***********************************************************************
     * RectangleShape
     * getPointCount

***********************************************************************/
std::size_t ach::RectangleShape::getPointCount() const
{
	return count * 4;
}



/***********************************************************************
     * RectangleShape
     * getPoint

***********************************************************************/
sf::Vector2f ach::RectangleShape::getPoint(std::size_t index) const
{
	sf::Vector2f c;

	int i = index / count;

	switch(i) {
		case 0: c.x = size.x - radius; c.y = radius         ; break;
		case 1: c.x = radius         ; c.y = radius         ; break;
		case 2: c.x = radius         ; c.y = size.y - radius; break;
		case 3: c.x = size.x - radius; c.y = size.y - radius; break;
	}

	if (count == 1)
		return c;


	float d = 90.0f / (count - 1);

	return sf::Vector2f( radius * cos(d * (index - i) * MATH_RAD) + c.x,
                        -radius * sin(d * (index - i) * MATH_RAD) + c.y);
}
