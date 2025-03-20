#ifndef __CHARACTER_AI_SNIPER
#define __CHARACTER_AI_SNIPER


namespace ach
{
	struct AISniper : AI
	{
		ach::Direction initial;
		ach::Direction dir;

		float cooldown;
		float offset;


		 AISniper(ach::Character *_owner, json_t *obj);
		~AISniper();

		void control();
		void aim();
		void reset();

		void collide(ach::PhysLine *line);
	};
}

#endif
