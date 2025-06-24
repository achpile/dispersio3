#ifndef __CHARACTER_AI_BOUNCER
#define __CHARACTER_AI_BOUNCER


namespace ach
{
	struct AIBouncer : AI
	{
		 AIBouncer(ach::Character *_owner, json_t *obj);
		~AIBouncer();
	};
}

#endif
