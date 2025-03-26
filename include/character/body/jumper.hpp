#ifndef __CHARACTER_BODY_JUMPER
#define __CHARACTER_BODY_JUMPER


namespace ach
{
	struct BodyJumper : Body
	{
		 BodyJumper(ach::Character *_owner, ach::DataModel *_base);
		~BodyJumper();

		void animate();
		void flip();
		void reset();
	};
}

#endif
