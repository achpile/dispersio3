#ifndef __CHARACTER_AI_CANNON
#define __CHARACTER_AI_CANNON


namespace ach
{
	struct AICannon : AI
	{
		 AICannon(ach::Character *_owner, json_t *obj);
		~AICannon();

		void reset();

		void collide(ach::PhysLine *line);
	};
}

#endif
