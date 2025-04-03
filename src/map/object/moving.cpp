#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectMoving
     * constructor

***********************************************************************/
ach::MapObjectMoving::MapObjectMoving(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	solid = true;

	setSheet(json_object_get_string(obj, "name"));

	model->layer = ach::RenderLayer::rlGame;

	ach::Direction d = pair_get_enum(json_class_get_string(obj, "Moving", "Direction"), pairDirection);
	sf::FloatRect  r = vector_json_rect(obj);

	orient  = dir_orient(d);
	speed   = json_property_get_real(obj, "Speed") * dir_sign(d);
	spawn   = phys.pos;

	min     = orient_rect_min(orient, r) + orient_v_coord(orient, phys.size) / 2.0f;
	max     = orient_rect_max(orient, r) - orient_v_coord(orient, phys.size) / 2.0f;

	float s = interval_set(json_property_get_real(obj, "Spawn"), 0.0, 1.0);

	if (dir_sign(d) == -1)
		s = 1.0f - s;

	orient_v_set(orient, &spawn, min + (max - min) * s);
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
	move = phys.pos;

	phys.update();

	if (!interval_check(orient_v_coord(orient, phys.pos), min, max))
	{
		orient_v_set(orient, &phys.pos, interval_wave(orient_v_coord(orient, phys.pos), min, max));
		phys.vel *= -1.0f;
	}

	phys.calc();

	move = phys.pos - move;

	list_foreach(linked)
	{
		linked[i]->pos += move;
		linked[i]->calc();
	}

	linked.clear();
}



/***********************************************************************
     * MapObjectMoving
     * stand

***********************************************************************/
void ach::MapObjectMoving::stand(ach::Phys *p)
{
	linked.push_back(p);
}
