#ifndef __CHARACTER_BODY_WALKING
#define __CHARACTER_BODY_WALKING


namespace ach
{
	struct BodyWalking : Body
	{
		 BodyWalking(ach::Character *_owner, ach::DataModel *_base);
		~BodyWalking();

		void aim();
		void animate();
		void flip();
		void reset();
	};
}

#endif
