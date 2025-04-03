#ifndef __CHARACTER_AI_LEVELER
#define __CHARACTER_AI_LEVELER


namespace ach
{
	struct AILeveler : AI
	{
		float cooldown;
		float offset;


		 AILeveler(ach::Character *_owner, json_t *obj);
		~AILeveler();

		void control();
		void reset();
	};
}

#endif
