#include "meta/headers.hpp"


/***********************************************************************
     * Camera
     * constructor

***********************************************************************/
ach::Camera::Camera()
{
	follower = NULL;
	viewport = sf::FloatRect(0, 0, RENDER_LAYER_GAME_X, RENDER_LAYER_GAME_Y);

	view.reset(viewport);
}



/***********************************************************************
     * Camera
     * destructor

***********************************************************************/
ach::Camera::~Camera()
{
}



/***********************************************************************
     * Camera
     * update

***********************************************************************/
void ach::Camera::update()
{
	center();
	check();

	view.reset(viewport);
	rm->setView(view);
}



/***********************************************************************
     * Camera
     * center

***********************************************************************/
void ach::Camera::center()
{
	if (!follower)
		return;

	viewport.left = follower->pos.x - RENDER_LAYER_GAME_X / 2.0f;
	viewport.top  = follower->pos.y - RENDER_LAYER_GAME_Y / 2.0f;
}



/***********************************************************************
     * Camera
     * check

***********************************************************************/
void ach::Camera::check()
{
	viewport.left = interval_set(viewport.left, area.left, area.left + area.width  - viewport.width );
	viewport.top  = interval_set(viewport.top , area.top , area.top  + area.height - viewport.height);
}



/***********************************************************************
     * Camera
     * follow

***********************************************************************/
void ach::Camera::follow(ach::Phys *phys)
{
	follower = phys;

	update();
}



/***********************************************************************
     * Camera
     * setArea

***********************************************************************/
void ach::Camera::setArea(sf::FloatRect _area)
{
	area = _area;

	update();
}
