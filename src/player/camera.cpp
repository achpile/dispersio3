#include "meta/headers.hpp"


/***********************************************************************
     * Camera
     * constructor

***********************************************************************/
ach::Camera::Camera()
{
	offset   = sf::Vector2f(0, 0);
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
	check();

	viewport.left = offset.x;
	viewport.top  = offset.y;

	view.reset(viewport);
	rm->setView(view);
}



/***********************************************************************
     * Camera
     * check

***********************************************************************/
void ach::Camera::check()
{
	if (offset.x < area.left)
		offset.x = area.left;

	if (offset.y < area.top)
		offset.y = area.top;

	if (offset.x > area.left + area.width - viewport.width)
		offset.x = area.left + area.width - viewport.width;

	if (offset.y > area.top + area.height - viewport.height)
		offset.y = area.top + area.height - viewport.height;
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
