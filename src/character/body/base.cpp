#include "meta/headers.hpp"


/***********************************************************************
     * Body
     * constructor

***********************************************************************/
ach::Body::Body(ach::Character *_owner, ach::DataBody*)
{
	owner  = _owner;
	barrel = sf::Vector2f(0.0f, 0.0f);
}



/***********************************************************************
     * Body
     * destructor

***********************************************************************/
ach::Body::~Body()
{
	list_delete(parts);
}



/***********************************************************************
     * Body
     * update

***********************************************************************/
void ach::Body::update()
{
	aim();
	animate();
	flip();

	list_update(parts);
}



/***********************************************************************
     * Body
     * setColor

***********************************************************************/
void ach::Body::setColor(sf::Color color)
{
	list_foreach(parts)
		parts[i]->model->color = color;
}



/***********************************************************************
     * Body
     * render

***********************************************************************/
void ach::Body::render()
{
	list_foreach(parts)
		parts[i]->render(owner->phys.pos);
}



/***********************************************************************
     * Body
     * create

***********************************************************************/
ach::Body* ach::Body::create(ach::Character *_owner, ach::DataBody *_base)
{
	switch (_base->type)
	{
		case ach::BodyType::btNone    : return new ach::Body        (_owner, _base);
		case ach::BodyType::btHumanoid: return new ach::BodyHumanoid(_owner, _base);

		default                       : return new ach::Body        (_owner, _base);
	}
}
