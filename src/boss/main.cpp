#include "meta/headers.hpp"


/***********************************************************************
     * BossMain
     * constructor

***********************************************************************/
ach::BossMain::BossMain(ach::ProcessWorld *_world, json_t *obj) : Boss(_world, obj)
{
	head  = new ach::Model(db->getModel(json_object_get_string(base->model, "Head" )));
	eyes  = new ach::Model(db->getModel(json_object_get_string(base->model, "Eyes" )));
	mouth = new ach::Model(db->getModel(json_object_get_string(base->model, "Mouth")));
	fistL = new ach::Model(db->getModel(json_object_get_string(base->model, "Fist" )));
	fistR = new ach::Model(db->getModel(json_object_get_string(base->model, "Fist" )));

	pos   = sf::Vector2f(rect_center(rect).x, rect.top + rect.height - 80);

	fistR->scale.x = -1;

	idle();
}



/***********************************************************************
     * BossMain
     * destructor

***********************************************************************/
ach::BossMain::~BossMain()
{
	delete head;
	delete eyes;
	delete mouth;
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
	eyes->update();
	mouth->update();
	fistL->update();
	fistR->update();

	head->render(pos);
	eyes->render(pos);
	mouth->render(pos);
	fistL->render(pos + sf::Vector2f(-32.0f, 16.0f - offsetL));
	fistR->render(pos + sf::Vector2f( 32.0f, 16.0f - offsetR));
}



/***********************************************************************
     * BossMain
     * respawn

***********************************************************************/
void ach::BossMain::respawn()
{
	state   = ach::BossMainState::bmsWait;
	offsetL = 0.0f;
	offsetR = 0.0f;

	timer.set(1.0f);

	idle();
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

				// TODO : remove debug
				pattern = 5;

				prepare();
			}
		break;


		case ach::BossMainState::bmsPattern:
			timer.update();
			evaluate();

			if (!timer.active())
			{
				timer.reset();
				attack();
			}
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

				head->setAnimation("Dead");
				eyes->setAnimation("Dead");
				mouth->setAnimation("Dead");
				fistL->setAnimation("Dead");
				fistR->setAnimation("Dead");
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
     * idle

***********************************************************************/
void ach::BossMain::idle()
{
	head->setAnimation("Idle");
	eyes->setAnimation("Idle");
	mouth->setAnimation("Idle");
	fistL->setAnimation("Idle");
	fistR->setAnimation("Idle");
}



/***********************************************************************
     * BossMain
     * patterns

***********************************************************************/
void ach::BossMain::patterns()
{
	list.clear();

	std::vector<int> p_eyes;
	std::vector<int> p_mouth;
	std::vector<int> p_fist;

	p_eyes.push_back(1);
	p_eyes.push_back(2);
	p_eyes.push_back(3);

	p_mouth.push_back(4);
	p_mouth.push_back(5);
	p_mouth.push_back(6);

	p_fist.push_back(7);
	p_fist.push_back(8);
	p_fist.push_back(9);

	random_shuffle(&p_eyes);
	random_shuffle(&p_mouth);
	random_shuffle(&p_fist);

	for (int i = 0; i < count(); i++)
	{
		list.push_back(p_eyes[i]);
		list.push_back(p_mouth[i]);
		list.push_back(p_fist[i]);

		random_shuffle(&list, 3 * i, 3);
	}
}



/***********************************************************************
     * BossMain
     * aim

***********************************************************************/
void ach::BossMain::aim(sf::Vector2f _pos, sf::Vector2f _dest)
{
	shot(_pos, _dest - _pos);
}



/***********************************************************************
     * BossMain
     * shot

***********************************************************************/
void ach::BossMain::shot(sf::Vector2f _pos, sf::Vector2f _dir)
{
	ach::Projectile *proj = new ach::Projectile(world, weapon->projectile);

	proj->phys.pos = _pos;
	proj->phys.vel = vector_set_len(_dir, weapon->speed);
	proj->enemy    = true;

	if (proj->phys.vel.x < 0.0f)
		proj->flip = true;

	proj->init();

	world->map->projectiles.push_back(proj);
	sm->play(weapon->shot->snd);
}



/***********************************************************************
     * BossMain
     * prepare

***********************************************************************/
void ach::BossMain::prepare()
{
	idle();

	counter = 0;
	offsetL = 0.0f;
	offsetR = 0.0f;

	switch (pattern)
	{
		case 1:
		break;

		// -------------------------------------------------------------

		case 2:
			eyes->setAnimation("Cross");

			timer.set(1.0f);

			weapon = db->getWeapon(json_object_get_string(base->weapon, "Cross"));
		break;

		// -------------------------------------------------------------

		case 3:
		break;

		// -------------------------------------------------------------

		case 4:
			mouth->setAnimation("Fire");

			timer.set(2.0f);

			weapon = db->getWeapon(json_object_get_string(base->weapon, "Fireball"));
		break;

		// -------------------------------------------------------------

		case 5:
			mouth->setAnimation("Blade");

			timer.set(2.0f);

			weapon = db->getWeapon(json_object_get_string(base->weapon, "Blade"));
		break;

		// -------------------------------------------------------------

		case 6:
		break;

		// -------------------------------------------------------------

		case 7:
			timer.set(0.75f);

			weapon = db->getWeapon(json_object_get_string(base->weapon, "Spike"));
		break;

		// -------------------------------------------------------------

		case 8:
			fistL->setAnimation("Up");
			fistR->setAnimation("Up");

			timer.set(2.0f);

			weapon = db->getWeapon(json_object_get_string(base->weapon, "Throw"));
		break;

		// -------------------------------------------------------------

		case 9:
			timer.set(2.5f);

			weapon = db->getWeapon(json_object_get_string(base->weapon, "Slam"));
		break;
	}
}



/***********************************************************************
     * BossMain
     * evaluate

***********************************************************************/
void ach::BossMain::evaluate()
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
			if (!timer.active())
				counter = !counter;

			offsetL = 0.0f;
			offsetR = 0.0f;

			if (counter) offsetL = 16.0f * sin(MATH_PI * math_sqr(timer.progress()));
			else         offsetR = 16.0f * sin(MATH_PI * math_sqr(timer.progress()));
		break;

		// -------------------------------------------------------------

		case 8:
		break;

		// -------------------------------------------------------------

		case 9:
			offsetR = offsetL = 16.0f * sin(MATH_PI * math_sqr(math_sqr(timer.progress())));
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
			aim(pos + sf::Vector2f(-6.0f, 1.0f), pos + (target->phys.pos - pos) / 3.0f);
			aim(pos + sf::Vector2f( 6.0f, 1.0f), pos + (target->phys.pos - pos) / 3.0f);

			counter++;

			if (counter == 3)
				counter =  0;

			if (counter) timer.set(0.4f);
			else         timer.set(1.0f);
		break;

		// -------------------------------------------------------------

		case 3:
		break;

		// -------------------------------------------------------------

		case 4:
			aim(pos, target->phys.pos);
		break;

		// -------------------------------------------------------------

		case 5:
			aim(pos, target->phys.pos);
		break;

		// -------------------------------------------------------------

		case 6:
		break;

		// -------------------------------------------------------------

		case 7:
			for (int i = 0; i < 5; i++)
				shot(sf::Vector2f(random_float(rect_value(rect, ach::Direction::dLeft) + 8.0f, rect_value(rect, ach::Direction::dRight) - 8.0f), rect.top + weapon->projectile->radius), sf::Vector2f(0.0f, 1.0f));
		break;

		// -------------------------------------------------------------

		case 8:
			if (counter)
			{
				fistL->setAnimation("Throw");
				fistL->anim.reset();
			}
			else
			{
				fistR->setAnimation("Throw");
				fistR->anim.reset();
			}

			shot(sf::Vector2f(pos.x + 32.0f * (counter ? -1 : 1), pos.y - 16.0f), sf::Vector2f(random_float(-50.0f, 50.0f), -100.0f));

			counter = !counter;
		break;

		// -------------------------------------------------------------

		case 9:
			shot(sf::Vector2f(rect_value(rect, ach::Direction::dLeft ) + random_float(8.0f, 104.0f), rect_value(rect, ach::Direction::dDown) - weapon->projectile->radius), sf::Vector2f(0.0f, -1.0f));
			shot(sf::Vector2f(rect_value(rect, ach::Direction::dLeft ) + random_float(8.0f, 104.0f), rect_value(rect, ach::Direction::dDown) - weapon->projectile->radius), sf::Vector2f(0.0f, -1.0f));

			shot(sf::Vector2f(rect_value(rect, ach::Direction::dRight) - random_float(8.0f, 104.0f), rect_value(rect, ach::Direction::dDown) - weapon->projectile->radius), sf::Vector2f(0.0f, -1.0f));
			shot(sf::Vector2f(rect_value(rect, ach::Direction::dRight) - random_float(8.0f, 104.0f), rect_value(rect, ach::Direction::dDown) - weapon->projectile->radius), sf::Vector2f(0.0f, -1.0f));
		break;
	}
}
