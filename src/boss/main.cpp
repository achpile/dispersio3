#include "meta/headers.hpp"


/***********************************************************************
     * BossMain
     * constructor

***********************************************************************/
ach::BossMain::BossMain(ach::ProcessWorld *_world, json_t *obj) : Boss(_world, obj)
{
	head  = new ach::Model(db->getModel(json_object_get_string(base->model, "Head")));
	fistL = new ach::Model(db->getModel(json_object_get_string(base->model, "Fist")));
	fistR = new ach::Model(db->getModel(json_object_get_string(base->model, "Fist")));

	pos   = sf::Vector2f(rect_center(rect).x, rect.top + rect.height - 80);

	fistR->scale.x = -1;
}



/***********************************************************************
     * BossMain
     * destructor

***********************************************************************/
ach::BossMain::~BossMain()
{
	delete head;
	delete fistL;
	delete fistR;
}



/***********************************************************************
     * BossMain
     * init

***********************************************************************/
void ach::BossMain::init()
{
	head->setAnimation("Idle");
	fistL->setAnimation("Idle");
	fistR->setAnimation("Idle");
}



/***********************************************************************
     * BossMain
     * render

***********************************************************************/
void ach::BossMain::render()
{
	head->update();
	fistL->update();
	fistR->update();

	head->render(pos);
	fistL->render(pos + sf::Vector2f(-32.0f, 16.0f));
	fistR->render(pos + sf::Vector2f( 32.0f, 16.0f));
}
