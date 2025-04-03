#ifndef __CHARACTER_AI_FOLLOW
#define __CHARACTER_AI_FOLLOW


namespace ach
{
	struct AIFollow : AI
	{
		 AIFollow(ach::Character *_owner, json_t *obj);
		~AIFollow();

		void control();
	};
}

#endif
