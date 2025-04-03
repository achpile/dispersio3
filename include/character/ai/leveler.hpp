#ifndef __CHARACTER_AI_LEVELER
#define __CHARACTER_AI_LEVELER


namespace ach
{
	struct AILeveler : AI
	{
		ach::Direction initial;
		ach::Direction dir;


		 AILeveler(ach::Character *_owner, json_t *obj);
		~AILeveler();

		void control();
		void reset();

		void collide(ach::PhysLine *line);
	};
}

#endif
