#ifndef __CHARACTER_BODY_PLAYER
#define __CHARACTER_BODY_PLAYER


namespace ach
{
	struct BodyPlayer : Body
	{
		 BodyPlayer(ach::Character *_owner, ach::DataModel *_base);
		~BodyPlayer();

		void aim();
		void animate();
		void flip();
		void reset();
	};
}

#endif
