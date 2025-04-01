#ifndef __CHARACTER_AI_JUMPER
#define __CHARACTER_AI_JUMPER


namespace ach
{
	struct AIJumper : AI
	{
		ach::Timer cooldown;

		int dir;


		 AIJumper(ach::Character *_owner, json_t *obj);
		~AIJumper();

		void physics();
		void control();
		void reset();

		void move();
		void jump();
	};
}

#endif
