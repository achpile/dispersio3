#include "meta/headers.hpp"


/***********************************************************************
     * Model
     * constructor

***********************************************************************/
ach::Model::Model(ach::DataModel *_base)
{
	base         = _base;
	color        = sf::Color::White;
	scale        = sf::Vector2f(1.0f, 1.0f);
	animation[0] = 0;

	anim.init(base->sheet->spr.size());
}



/***********************************************************************
     * Model
     * destructor

***********************************************************************/
ach::Model::~Model()
{
}



/***********************************************************************
     * Model
     * update

***********************************************************************/
void ach::Model::update()
{
	anim.update();
}



/***********************************************************************
     * Model
     * render

***********************************************************************/
void ach::Model::render(sf::Vector2f pos)
{
	sf::Sprite *spr = base->sheet->spr[anim.frame];

	spr->setColor(color);
	spr->setScale(scale);
	spr->setPosition(pos);

	rm->draw(spr, ach::RenderLayer::rlGame);
}



/***********************************************************************
     * Model
     * setAnimation

***********************************************************************/
void ach::Model::setAnimation(const char *name)
{
	if (!strcmp(animation, name))
		return;

	json_t *obj = json_object_get(base->animation, name);

	if (!obj)
		return;

	strncpy(animation, name, STR_LEN_NAME);

	anim.set(json_object_get_integer(obj, "Start"),
	         json_object_get_integer(obj, "End"  ),
	         json_object_get_boolean(obj, "Loop" ),
	         json_object_get_real   (obj, "Rate" ));
}
