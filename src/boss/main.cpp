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

	head->setAnimation("Idle");
	fistL->setAnimation("Idle");
	fistR->setAnimation("Idle");
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



/***********************************************************************
     * BossMain
     * respawn

***********************************************************************/
void ach::BossMain::respawn()
{
	state = ach::BossMainState::bmsWait;

	head->setAnimation("Idle");
	fistL->setAnimation("Idle");
	fistR->setAnimation("Idle");

	timer.set(1.0f);
}



/***********************************************************************
     * BossMain
     * handle

***********************************************************************/
void ach::BossMain::handle()
{
	switch (state)
	{
		case ach::BossMainState::bmsWait:
			if (!timer.update())
			{
				state = ach::BossMainState::bmsPattern;

				prepare();
			}
		break;


		case ach::BossMainState::bmsPattern:
			attack();
		break;


		case ach::BossMainState::bmsDamage:
			{
				timer.set(1.0f);
				state = ach::BossMainState::bmsWait;
			}
		break;


		case ach::BossMainState::bmsDefeated:
			if (!timer.update())
				defeated = true;
		break;
	}
}



/***********************************************************************
     * BossMain
     * prepare

***********************************************************************/
void ach::BossMain::prepare()
{
	switch (pattern)
	{
		case 1:
		break;

		// -------------------------------------------------------------

		case 2:
		break;

		// -------------------------------------------------------------

		case 3:
		break;

		// -------------------------------------------------------------

		case 4:
		break;

		// -------------------------------------------------------------

		case 5:
		break;

		// -------------------------------------------------------------

		case 6:
		break;

		// -------------------------------------------------------------

		case 7:
		break;

		// -------------------------------------------------------------

		case 8:
		break;

		// -------------------------------------------------------------

		case 9:
		break;
	}
}



/***********************************************************************
     * BossMain
     * attack

***********************************************************************/
void ach::BossMain::attack()
{
	switch (pattern)
	{
		case 1:
		break;

		// -------------------------------------------------------------

		case 2:
		break;

		// -------------------------------------------------------------

		case 3:
		break;

		// -------------------------------------------------------------

		case 4:
		break;

		// -------------------------------------------------------------

		case 5:
		break;

		// -------------------------------------------------------------

		case 6:
		break;

		// -------------------------------------------------------------

		case 7:
		break;

		// -------------------------------------------------------------

		case 8:
		break;

		// -------------------------------------------------------------

		case 9:
		break;
	}
}
