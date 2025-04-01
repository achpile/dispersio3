#ifndef __CHARACTER_AI_PLAYER
#define __CHARACTER_AI_PLAYER


namespace ach
{
	struct AIPlayer : AI
	{
		bool jumped;


		 AIPlayer(ach::Character *_owner, json_t *obj);
		~AIPlayer();

		void physics();
		void control();
		void reset();

		void collide(ach::PhysLine *line);

		void move(int d);
		void jump();
	};
}

#endif
