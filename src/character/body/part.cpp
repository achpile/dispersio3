#include "meta/headers.hpp"


/***********************************************************************
     * BodyPart
     * constructor

***********************************************************************/
ach::BodyPart::BodyPart(json_t *obj)
{
	model  = new ach::Model(db->getModel(json_object_get_string(obj, "Model")));
	offset = vector_json_coord(json_object_get(obj, "Offset"), "X", "Y");
}



/***********************************************************************
     * BodyPart
     * destructor

***********************************************************************/
ach::BodyPart::~BodyPart()
{
	delete model;
}



/***********************************************************************
     * BodyPart
     * update

***********************************************************************/
bool ach::BodyPart::update()
{
	model->update();

	return true;
}



/***********************************************************************
     * BodyPart
     * render

***********************************************************************/
void ach::BodyPart::render(sf::Vector2f pos)
{
	model->render(offset + pos);
}



/***********************************************************************
     * BodyPart
     * setAnimation

***********************************************************************/
void ach::BodyPart::setAnimation(const char *name)
{
	model->setAnimation(name);
}
