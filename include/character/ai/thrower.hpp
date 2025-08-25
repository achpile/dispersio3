#ifndef __CHARACTER_AI_THROWER
#define __CHARACTER_AI_THROWER


namespace ach
{
	struct AIThrower : AI
	{
		ach::Direction aim;

		float cooldown;
		float offset;


		 AIThrower(ach::Character *_owner, json_t *obj);
		~AIThrower();

		void control();
		void reset();
	};
}

#endif
