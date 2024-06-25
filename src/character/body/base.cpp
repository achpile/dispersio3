#include "meta/headers.hpp"


/***********************************************************************
     * Body
     * constructor

***********************************************************************/
ach::Body::Body(ach::Character *_owner, ach::DataBody*)
{
	owner = _owner;
}



/***********************************************************************
     * Body
     * destructor

***********************************************************************/
ach::Body::~Body()
{
	listDelete(parts);
}



/***********************************************************************
     * Body
     * update

***********************************************************************/
void ach::Body::update()
{
	listUpdate(parts);
}



/***********************************************************************
     * Body
     * setColor

***********************************************************************/
void ach::Body::setColor(sf::Color color)
{
	for (unsigned int i = 0; i < parts.size(); i++)
		parts[i]->model->color = color;
}



/***********************************************************************
     * Body
     * render

***********************************************************************/
void ach::Body::render()
{
	for (unsigned int i = 0; i < parts.size(); i++)
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
