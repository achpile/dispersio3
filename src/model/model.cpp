#include "meta/headers.hpp"


/***********************************************************************
     * Model
     * constructor

***********************************************************************/
ach::Model::Model(ach::DataModel *_base)
{
	base         = _base;
	animation[0] = 0;

	init(base->sheet);
}



/***********************************************************************
     * Model
     * constructor

***********************************************************************/
ach::Model::Model(ach::DataSheet *_sheet)
{
	base = NULL;

	init(_sheet);
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
	sf::Sprite *spr = sheet->getFrame(anim.frame);

	spr->setColor(color);
	spr->setScale(scale);
	spr->setPosition(pos);
	spr->setRotation(angle);

	rm->draw(spr, ach::RenderLayer::rlGame);
}



/***********************************************************************
     * Model
     * init

***********************************************************************/
void ach::Model::init(ach::DataSheet *_sheet)
{
	sheet = _sheet->sheet;
	angle = 0.0f;

	setColor(sf::Color::White);
	setScale(1.0f);

	anim.init(sheet->spr.size(), _sheet->rate);
}



/***********************************************************************
     * Model
     * setAnimation

***********************************************************************/
void ach::Model::setAnimation(const char *name)
{
	if (!base)
		return;

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



/***********************************************************************
     * Model
     * setScale

***********************************************************************/
void ach::Model::setScale(float _scale)
{
	scale = sf::Vector2f(_scale, _scale);
}



/***********************************************************************
     * Model
     * setColor

***********************************************************************/
void ach::Model::setColor(sf::Color _color)
{
	color = _color;
}
