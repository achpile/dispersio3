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

	patterns();
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
				state   = ach::BossMainState::bmsPattern;
				pattern = list.back();

				list.pop_back();
				prepare();
			}
		break;


		case ach::BossMainState::bmsPattern:
			attack();
		break;


		case ach::BossMainState::bmsDamage:
			if (list.size())
			{
				timer.set(1.0f);
				state = ach::BossMainState::bmsWait;
			}
			else
			{
				timer.set(3.0f);
				state = ach::BossMainState::bmsDefeated;
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
     * collide

***********************************************************************/
bool ach::BossMain::collide(sf::FloatRect r)
{
	if (r.intersects(sf::FloatRect(pos.x - 16.0f, pos.y - 16.0f, 32.0f, 32.0f))) return true;
	if (r.intersects(sf::FloatRect(pos.x - 48.0f, pos.y        , 32.0f, 32.0f))) return true;
	if (r.intersects(sf::FloatRect(pos.x + 16.0f, pos.y        , 32.0f, 32.0f))) return true;

	return false;
}



/***********************************************************************
     * BossMain
     * count

***********************************************************************/
int ach::BossMain::count()
{
	if (cache->mode == ach::LevelMode::lmTraining)
		return 3;

	switch (cache->difficulty)
	{
		case ach::Difficulty::gdEasy  : return 1;
		case ach::Difficulty::gdNormal: return 2;
		case ach::Difficulty::gdHard  : return 3;
	}

	return 0;
}



/***********************************************************************
     * BossMain
     * patterns

***********************************************************************/
void ach::BossMain::patterns()
{
	list.clear();

	std::vector<int> eyes;
	std::vector<int> mouth;
	std::vector<int> fist;

	eyes.push_back(1);
	eyes.push_back(2);
	eyes.push_back(3);

	mouth.push_back(4);
	mouth.push_back(5);
	mouth.push_back(6);

	fist.push_back(7);
	fist.push_back(8);
	fist.push_back(9);

	random_shuffle(&eyes);
	random_shuffle(&mouth);
	random_shuffle(&fist);

	for (int i = 0; i < count(); i++)
	{
		list.push_back(eyes[i]);
		list.push_back(mouth[i]);
		list.push_back(fist[i]);

		random_shuffle(&list, 3 * i, 3);
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
