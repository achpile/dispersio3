#ifndef __CHARACTER_AI_PLAYER
#define __CHARACTER_AI_PLAYER


namespace ach
{
	struct AIPlayer : AI
	{
		 AIPlayer(ach::Character *_owner);
		~AIPlayer();

		void control();
		void aim();

		void move(int d, bool hold);
	};
}

#endif
