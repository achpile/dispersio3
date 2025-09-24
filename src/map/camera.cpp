#include "meta/headers.hpp"


/***********************************************************************
     * Camera
     * constructor

***********************************************************************/
ach::Camera::Camera(ach::Map *_map)
{
	map      = _map;
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
	if (!follower)
		return;

	if (!area.contains(follower->pos))
		set(map->findMapArea(follower->pos));

	viewport.left = round(follower->pos.x - RENDER_LAYER_GAME_X / 2.0f);
	viewport.top  = round(follower->pos.y - RENDER_LAYER_GAME_Y / 2.0f);

	viewport.left = interval_set(viewport.left, area.left, area.left + area.width  - viewport.width );
	viewport.top  = interval_set(viewport.top , area.top , area.top  + area.height - viewport.height);

	view.reset(viewport);
	rm->setView(view);
}



/***********************************************************************
     * Camera
     * check

***********************************************************************/
bool ach::Camera::check(sf::Vector2f v, bool _area)
{
	if (_area) return area.contains(v);
	else       return viewport.contains(v);
}



/***********************************************************************
     * Camera
     * check

***********************************************************************/
bool ach::Camera::check(sf::FloatRect r, bool _area)
{
	if (_area) return area.intersects(r);
	else       return viewport.intersects(r);
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
     * set

***********************************************************************/
void ach::Camera::set(ach::MapArea *_area)
{
	area = _area->rect;

	map->viewport(_area);
}
