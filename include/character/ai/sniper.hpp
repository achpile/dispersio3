#ifndef __CHARACTER_AI_SNIPER
#define __CHARACTER_AI_SNIPER


namespace ach
{
	struct AISniper : AI
	{
		ach::Direction dir;

		float cooldown;
		float offset;


		 AISniper(ach::Character *_owner, json_t *obj);
		~AISniper();

		void reset();
	};
}

#endif
