#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectWind
     * constructor

***********************************************************************/
ach::MapObjectWind::MapObjectWind(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	dir   = pair_get_enum(json_property_get_string(obj, "Direction"), pairDirection);
	speed = json_property_get_real(obj, "Speed");

	stream = dir_vector_f(dir) * speed;
	wind   = new ach::ParticleSystemWind(phys.rect, dir, speed);
}



/***********************************************************************
     * MapObjectWind
     * destructor

***********************************************************************/
ach::MapObjectWind::~MapObjectWind()
{
	delete wind;
}



/***********************************************************************
     * MapObjectWind
     * touch

***********************************************************************/
void ach::MapObjectWind::touch()
{
	if (dir == ach::Direction::dUp && world->player->phys.grounded)
		return;

	world->player->phys.pos += stream * tm->get();
}



/***********************************************************************
     * MapObjectWind
     * post

***********************************************************************/
void ach::MapObjectWind::post()
{
	wind->update();
	wind->render();
}
