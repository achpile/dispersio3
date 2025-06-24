#ifndef __CHARACTER_AI_BOUNCER
#define __CHARACTER_AI_BOUNCER


namespace ach
{
	struct AIBouncer : AI
	{
		ach::Direction   initial;
		ach::Direction   dir;
		ach::Orientation orient;

		ach::Timer       cooldown;

		bool  grounded;
		float range;


		 AIBouncer(ach::Character *_owner, json_t *obj);
		~AIBouncer();

		void control();
		void reset();

		void collide(ach::PhysLine *line);
	};
}

#endif
