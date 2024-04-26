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
	viewport.left = offset.x;
	viewport.top  = offset.y;

	view.reset(viewport);
	rm->setView(view);
}
