#include "meta/headers.hpp"


/***********************************************************************
     * MapObjectYoku
     * constructor

***********************************************************************/
ach::MapObjectYoku::MapObjectYoku(ach::ProcessWorld *_world, json_t *obj) : MapObject(_world, obj)
{
	duration = json_property_get_real(obj, "Duration");
	cooldown = json_property_get_real(obj, "Cooldown");
	offset   = json_property_get_real(obj, "Offset"  );

	pushing  = pair_get_enum(json_property_get_string(obj, "Push"), pairOrientation);
	sfx      = db->getSound(json_object_get_branch_string(dm->data, "Data.Game.Meta.SFX.Yoku"));

	setSheet(json_object_get_string(obj, "name"));

	model->anim.loop = false;
	model->layer     = ach::RenderLayer::rlFront;
}



/***********************************************************************
     * MapObjectYoku
     * destructor

***********************************************************************/
ach::MapObjectYoku::~MapObjectYoku()
{
}



/***********************************************************************
     * MapObjectYoku
     * reset

***********************************************************************/
void ach::MapObjectYoku::reset()
{
	alive = offset < 0.0f;

	state();

	timer.value = fabs(offset);

	if (alive)
		model->anim.frame = model->anim.end;
}



/***********************************************************************
     * MapObjectYoku
     * handle

***********************************************************************/
void ach::MapObjectYoku::handle()
{
	if (!timer.update())
		return;

	alive = !alive;

	state();

	if (alive)
	{
		push(&world->player->phys);
		model->anim.reset();
		sm->play(sfx->snd);
	}
}



/***********************************************************************
     * MapObjectYoku
     * state

***********************************************************************/
void ach::MapObjectYoku::state()
{
	timer.set(alive ? duration : cooldown);

	solid = alive;
}



/***********************************************************************
     * MapObjectYoku
     * push

***********************************************************************/
void ach::MapObjectYoku::push(ach::Phys *character)
{
	if (!phys.rect.intersects(character->rect))
		return;

	sf::Vector2f off = sf::Vector2f(0.0f, 0.0f);

	sf::Vector2f lt  = rect_lt(phys.rect) - character->pos;
	sf::Vector2f rb  = rect_rb(phys.rect) - character->pos;

	lt.x -= character->rect.width  / 2.0f;
	lt.y -= character->rect.height / 2.0f;
	rb.x += character->rect.width  / 2.0f;
	rb.y += character->rect.height / 2.0f;

	off.x = (fabs(lt.x) < fabs(rb.x)) ? lt.x : rb.x;
	off.y = (fabs(lt.y) < fabs(rb.y)) ? lt.y : rb.y;

	switch (pushing)
	{
		case ach::oVertical  : off.x = 0.0f; break;
		case ach::oHorizontal: off.y = 0.0f; break;

		default:
			if (fabs(off.x) < fabs(off.y)) off.y = 0.0f;
			else                           off.x = 0.0f;
		break;
	}

	character->pos += off;
	character->calc();
}
