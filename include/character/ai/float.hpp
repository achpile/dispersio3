#ifndef __CHARACTER_AI_FLOAT
#define __CHARACTER_AI_FLOAT


namespace ach
{
	struct AIFloat : AI
	{
		 AIFloat(ach::Character *_owner, json_t *obj);
		~AIFloat();

		void control();

		void collide(ach::PhysLine *line);
	};
}

#endif
