#include "meta/headers.hpp"


/***********************************************************************
     * Camera
     * constructor

***********************************************************************/
ach::Camera::Camera(ach::Map *_map)
{
	map      = _map;
	follower = NULL;
	pos      = sf::Vector2i (0, 0);
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
	if (!follower)
		return;

	if (!check(follower->pos))
		map->viewport(follower->pos);

	view.reset(viewport);
	rm->setView(view);
}



/***********************************************************************
     * Camera
     * check

***********************************************************************/
bool ach::Camera::check(sf::Vector2f v)
{
	return viewport.contains(v);
}



/***********************************************************************
     * Camera
     * check

***********************************************************************/
bool ach::Camera::check(sf::FloatRect r)
{
	return viewport.intersects(r);
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
     * calc

***********************************************************************/
void ach::Camera::calc()
{
	viewport.left = pos.x * viewport.width;
	viewport.top  = pos.y * viewport.height;

	tiles.left    = pos.x * tiles.width;
	tiles.top     = pos.y * tiles.height;
}
