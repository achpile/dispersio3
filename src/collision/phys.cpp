#include "meta/headers.hpp"


/***********************************************************************
     * Phys
     * update

***********************************************************************/
void ach::Phys::update()
{
	vel += acc * tm->get();
	pos += vel * tm->get();

	calc();
}



/***********************************************************************
     * Phys
     * calc

***********************************************************************/
void ach::Phys::calc()
{
	rect.left = pos.x - rect.width  / 2.0f;
	rect.top  = pos.y - rect.height / 2.0f;
}



/***********************************************************************
     * Phys
     * init

***********************************************************************/
void ach::Phys::init(sf::Vector2f _size)
{
	size = _size;
	rect = sf::FloatRect(sf::Vector2f(0.0f, 0.0f), size);

	reset();
}



/***********************************************************************
     * Phys
     * init

***********************************************************************/
void ach::Phys::init(sf::FloatRect _rect)
{
	rect = _rect;
	size = rect_size(rect);
	pos  = rect_center(rect);

	reset();
}



/***********************************************************************
     * Phys
     * resize

***********************************************************************/
void ach::Phys::resize(sf::Vector2f _size)
{
	size = _size;

	rect.width  = size.x;
	rect.height = size.y;

	reset();
}



/***********************************************************************
     * Phys
     * reset

***********************************************************************/
void ach::Phys::reset()
{
	acc = sf::Vector2f(0.0f, 0.0f);
	vel = sf::Vector2f(0.0f, 0.0f);

	slope    = 0.0f;
	water    = 0.0f;
	gravity  = 1;

	grounded = true;
	moving   = false;
	jumpdown = false;
	bounce   = false;

	calc();
}
