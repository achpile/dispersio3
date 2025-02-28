#ifndef __CHARACTER_AI_FLOAT
#define __CHARACTER_AI_FLOAT


namespace ach
{
	struct AIFloat : AI
	{
		ach::Direction initial;
		ach::Direction dir;


		 AIFloat(ach::Character *_owner, json_t *obj);
		~AIFloat();

		void control();
		void reset();

		void collide(ach::PhysLine *line);
	};
}

#endif
