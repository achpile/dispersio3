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

	warning   = db->getSheet(json_object_get_string(base->gfx, "Warning"  ));
	explosion = db->getSheet(json_object_get_string(base->gfx, "Explosion"));
	boulder   = db->getSheet(json_object_get_string(base->gfx, "Boulder"  ));

	expl      = db->getSound(json_object_get_string(base->sfx, "Explosion"));

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
				state   = ach::BossMainState::bmsPrepare;
				pattern = list.back();
				list.pop_back();

				prepare();
				warnings();
				activate();
			}
		break;


		case ach::BossMainState::bmsPrepare:
			if (!timer.update())
			{
				state = ach::BossMainState::bmsPattern;

				initialize();
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
				unpress();

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
     * damage

***********************************************************************/
void ach::BossMain::damage()
{
	list_delete(world->map->projectiles);

	state = ach::BossMainState::bmsDamage;
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
     * warn

***********************************************************************/
void ach::BossMain::warn(sf::Vector2f _pos)
{
	world->map->gfx.push_back(new ach::EffectSheet(warning, _pos, warning->sheet->size.y));
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

	timer.set(1.0f);

	switch (pattern)
	{
		case 1:
			eyes->setAnimation("Fire");

			weapon = db->getWeapon(json_object_get_string(base->weapon, "Explosion"));
		break;

		// -------------------------------------------------------------

		case 2:
			eyes->setAnimation("Cross");

			weapon = db->getWeapon(json_object_get_string(base->weapon, "Cross"));
		break;

		// -------------------------------------------------------------

		case 3:
			eyes->setAnimation("Rotate");

			counter = -14;
			weapon  = db->getWeapon(json_object_get_string(base->weapon, "Cross"));
		break;

		// -------------------------------------------------------------

		case 4:
			mouth->setAnimation("Fire");

			weapon = db->getWeapon(json_object_get_string(base->weapon, "Fireball"));
		break;

		// -------------------------------------------------------------

		case 5:
			mouth->setAnimation("Blade");

			weapon = db->getWeapon(json_object_get_string(base->weapon, "Blade"));
		break;

		// -------------------------------------------------------------

		case 6:
			mouth->setAnimation("Rainbow");

			weapon = db->getWeapon(json_object_get_string(base->weapon, "Cross"));
		break;

		// -------------------------------------------------------------

		case 7:
			timer.zero();

			weapon = db->getWeapon(json_object_get_string(base->weapon, "Spike"));
		break;

		// -------------------------------------------------------------

		case 8:
			fistL->setAnimation("Up");
			fistR->setAnimation("Up");

			weapon = db->getWeapon(json_object_get_string(base->weapon, "Throw"));
		break;

		// -------------------------------------------------------------

		case 9:
			timer.zero();

			weapon = db->getWeapon(json_object_get_string(base->weapon, "Slam"));
		break;
	}
}



/***********************************************************************
     * BossMain
     * warnings

***********************************************************************/
void ach::BossMain::warnings()
{
	switch (pattern)
	{
		case 1:
			warn(target->phys.pos);
		break;

		// -------------------------------------------------------------

		case 2:
			warn(target->phys.pos);
		break;

		// -------------------------------------------------------------

		case 3:
			warn(pos + sf::Vector2f( 96.0f, 16.0f));
			warn(pos + sf::Vector2f(-96.0f, 16.0f));
		break;

		// -------------------------------------------------------------

		case 4:
			warn(target->phys.pos);
		break;

		// -------------------------------------------------------------

		case 5:
			warn(target->phys.pos);
		break;

		// -------------------------------------------------------------

		case 6:
			warn(pos + sf::Vector2f(   0.0f, -112.0f));
			warn(pos + sf::Vector2f(  80.0f,  -96.0f));
			warn(pos + sf::Vector2f( -80.0f,  -96.0f));
			warn(pos + sf::Vector2f( 120.0f,  -24.0f));
			warn(pos + sf::Vector2f(-120.0f,  -24.0f));
		break;

		// -------------------------------------------------------------

		case 7:
			warn(pos + sf::Vector2f(   0.0f, -128.0f));
			warn(pos + sf::Vector2f(  72.0f, -128.0f));
			warn(pos + sf::Vector2f( -72.0f, -128.0f));
			warn(pos + sf::Vector2f( 144.0f, -128.0f));
			warn(pos + sf::Vector2f(-144.0f, -128.0f));
		break;

		// -------------------------------------------------------------

		case 8:
			warn(pos + sf::Vector2f(32.0f, -16.0f));
		break;

		// -------------------------------------------------------------

		case 9:
			warn(pos + sf::Vector2f(  72.0f, 48.0f));
			warn(pos + sf::Vector2f( -72.0f, 48.0f));
			warn(pos + sf::Vector2f( 144.0f, 48.0f));
			warn(pos + sf::Vector2f(-144.0f, 48.0f));
		break;
	}
}



/***********************************************************************
     * BossMain
     * initialize

***********************************************************************/
void ach::BossMain::initialize()
{
	switch (pattern)
	{
		case 1: timer.set(1.0f ); break;
		case 2: timer.set(1.0f ); break;
		case 3: timer.set(0.3f ); break;
		case 4: timer.set(2.0f ); break;
		case 5: timer.set(2.0f ); break;
		case 6: timer.set(1.0f ); break;
		case 7: timer.set(0.75f); break;
		case 8: timer.set(2.0f ); break;
		case 9: timer.set(2.5f ); break;
	}

	switch (pattern)
	{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 8:
			timer.zero();
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
		case 7:
			if (!timer.active())
				counter = !counter;

			offsetL = 0.0f;
			offsetR = 0.0f;

			if (counter) offsetL = 16.0f * sin(MATH_PI * math_sqr(timer.progress()));
			else         offsetR = 16.0f * sin(MATH_PI * math_sqr(timer.progress()));
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
			warn(target->phys.pos);
			shot(target->phys.pos, sf::Vector2f(0.0f, 1.0f));
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
			shot(pos + sf::Vector2f(-6.0f, 1.0f), vector_create(-MATH_PI * (12 + abs(counter)) / 24.0f));
			shot(pos + sf::Vector2f( 6.0f, 1.0f), vector_create(-MATH_PI * (12 - abs(counter)) / 24.0f));

			counter++;

			if (counter == 12)
				counter = -14;
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

			if (counter)
			{
				shot(pos + sf::Vector2f(0.0f, 10.0f), sf::Vector2f( 6.0f,  1.0f));
				shot(pos + sf::Vector2f(0.0f, 10.0f), sf::Vector2f(-6.0f,  1.0f));
				shot(pos + sf::Vector2f(0.0f, 10.0f), sf::Vector2f( 4.0f, -3.0f));
				shot(pos + sf::Vector2f(0.0f, 10.0f), sf::Vector2f(-4.0f, -3.0f));
				shot(pos + sf::Vector2f(0.0f, 10.0f), sf::Vector2f(-1.0f, -3.0f));
				shot(pos + sf::Vector2f(0.0f, 10.0f), sf::Vector2f( 1.0f, -3.0f));
			}
			else
			{
				shot(pos + sf::Vector2f(0.0f, 10.0f), sf::Vector2f( 0.0f, -1.0f));
				shot(pos + sf::Vector2f(0.0f, 10.0f), sf::Vector2f( 4.0f, -1.0f));
				shot(pos + sf::Vector2f(0.0f, 10.0f), sf::Vector2f(-4.0f, -1.0f));
				shot(pos + sf::Vector2f(0.0f, 10.0f), sf::Vector2f(-2.0f, -3.0f));
				shot(pos + sf::Vector2f(0.0f, 10.0f), sf::Vector2f( 2.0f, -3.0f));
			}

			counter = !counter;
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
