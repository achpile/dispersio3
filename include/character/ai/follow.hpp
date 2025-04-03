#ifndef __CHARACTER_AI_FOLLOW
#define __CHARACTER_AI_FOLLOW


namespace ach
{
	struct AIFollow : AI
	{
		ach::Direction initial;
		ach::Direction dir;


		 AIFollow(ach::Character *_owner, json_t *obj);
		~AIFollow();

		void control();
		void reset();

		void collide(ach::PhysLine *line);
	};
}

#endif
