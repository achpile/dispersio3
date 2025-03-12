#ifndef __CHARACTER_AI_CANNON
#define __CHARACTER_AI_CANNON


namespace ach
{
	struct AICannon : AI
	{
		ach::Direction dir;

		float cooldown;
		float offset;


		 AICannon(ach::Character *_owner, json_t *obj);
		~AICannon();

		void reset();
	};
}

#endif
