#ifndef __CHARACTER_BODY_PLAYER
#define __CHARACTER_BODY_PLAYER


namespace ach
{
	struct BodyPlayer : Body
	{
		ach::DataSheet *spawning;


		 BodyPlayer(ach::Character *_owner, ach::DataModel *_base);
		~BodyPlayer();

		void aim();
		void animate();
		void spawn();
		void flip();
		void reset();
	};
}

#endif
