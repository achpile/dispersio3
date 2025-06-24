#ifndef __CHARACTER_BODY_MOVING
#define __CHARACTER_BODY_MOVING


namespace ach
{
	struct BodyMoving : Body
	{
		 BodyMoving(ach::Character *_owner, ach::DataModel *_base);
		~BodyMoving();

		void animate();
		void flip();
		void reset();
	};
}

#endif
