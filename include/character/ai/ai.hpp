#ifndef __CHARACTER_AI_AI
#define __CHARACTER_AI_AI


namespace ach
{
	struct AI
	{
		ach::Character *owner;


		         AI(ach::Character *_owner, json_t *obj);
		virtual ~AI();

		void update();

		virtual void control();
		virtual void aim()   {};
		virtual void reset() {};

		virtual void collide(ach::PhysLine *line);

		static ach::AI *create(ach::Character *_owner, ach::AIType type, json_t *obj);
	};
}

#endif
