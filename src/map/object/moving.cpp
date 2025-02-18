#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectMoving
     * constructor

***********************************************************************/
ach::MapObjectMoving::MapObjectMoving(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	solid = true;

	setSheet(json_object_get_string(obj, "name"));

	sf::FloatRect r = vector_json_rect(obj);

	orient = pair_get_enum(json_class_get_string(obj, "Moving", "Orientation"), pairOrientation);
	speed  = json_class_get_real(obj, "Moving", "Speed");
	spawn  = phys.pos;

	min    = orient_rect_min(orient, r) + orient_v_coord(orient, phys.size) / 2.0f;
	max    = orient_rect_max(orient, r) - orient_v_coord(orient, phys.size) / 2.0f;

	orient_v_set(orient, &spawn, min + (max - min) * interval_set(json_property_get_real(obj, "Spawn"), 0.0, 1.0));
}



/***********************************************************************
     * MapObjectMoving
     * destructor

***********************************************************************/
ach::MapObjectMoving::~MapObjectMoving()
{
}



/***********************************************************************
     * MapObjectMoving
     * reset

***********************************************************************/
void ach::MapObjectMoving::reset()
{
	phys.pos = spawn;
	phys.vel = orient_v_create(orient) * speed;

	phys.calc();
}



/***********************************************************************
     * MapObjectMoving
     * handle

***********************************************************************/
void ach::MapObjectMoving::handle()
{
	phys.update();

	if (!interval_check(orient_v_coord(orient, phys.pos), min, max))
	{
		orient_v_set(orient, &phys.pos, interval_wave(orient_v_coord(orient, phys.pos), min, max));
		phys.vel *= -1.0f;
	}

	phys.calc();
}
