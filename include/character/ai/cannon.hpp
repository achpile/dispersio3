#ifndef __CHARACTER_AI_CANNON
#define __CHARACTER_AI_CANNON


namespace ach
{
	struct AICannon : AI
	{
		ach::Direction initial;
		ach::Direction dir;
		ach::Direction aim;

		float cooldown;
		float offset;


		 AICannon(ach::Character *_owner, json_t *obj);
		~AICannon();

		void control();
		void reset();

		void collide(ach::PhysLine *line);
	};
}

#endif
