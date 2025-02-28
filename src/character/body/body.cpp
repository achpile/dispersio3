#include "meta/headers.hpp"


/***********************************************************************
     * Body
     * constructor

***********************************************************************/
ach::Body::Body(ach::Character *_owner, ach::DataModel* _base)
{
	owner  = _owner;
	barrel = sf::Vector2f(0.0f, 0.0f);
	model  = new ach::Model(_base);
}



/***********************************************************************
     * Body
     * destructor

***********************************************************************/
ach::Body::~Body()
{
	delete model;
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

	model->update();
}



/***********************************************************************
     * Body
     * setColor

***********************************************************************/
void ach::Body::setColor(sf::Color color)
{
	model->color = color;
}



/***********************************************************************
     * Body
     * setDirection

***********************************************************************/
void ach::Body::setDirection(ach::Direction dir)
{
	switch (dir)
	{
		case ach::Direction::dUp:
			model->scale.x =  1.0f;
			model->scale.y =  1.0f;
			model->angle   =  0.0f;
			break;

		case ach::Direction::dDown:
			model->scale.x =  1.0f;
			model->scale.y = -1.0f;
			model->angle   =  0.0f;
			break;

		case ach::Direction::dLeft:
			model->scale.x =  1.0f;
			model->scale.y =  1.0f;
			model->angle   = -90;
			break;

		case ach::Direction::dRight:
			model->scale.x =  1.0f;
			model->scale.y =  1.0f;
			model->angle   =  90;
			break;

		case ach::Direction::dCount:
			model->scale.x =  1.0f;
			model->scale.y =  1.0f;
			model->angle   =  0;
			break;
	}
}



/***********************************************************************
     * Body
     * render

***********************************************************************/
void ach::Body::render()
{
	model->render(owner->phys.pos);
}



/***********************************************************************
     * Body
     * create

***********************************************************************/
ach::Body* ach::Body::create(ach::Character *_owner, ach::DataModel *_base)
{
	switch (_base->type)
	{
		case ach::ModelType::mtNone  : return new ach::Body      (_owner, _base);
		case ach::ModelType::mtSimple: return new ach::BodySimple(_owner, _base);
		case ach::ModelType::mtPlayer: return new ach::BodyPlayer(_owner, _base);
	}

	return new ach::Body(_owner, _base);
}
