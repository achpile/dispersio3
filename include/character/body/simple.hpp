#ifndef __CHARACTER_BODY_SIMPLE
#define __CHARACTER_BODY_SIMPLE


namespace ach
{
	struct BodySimple : Body
	{
		 BodySimple(ach::Character *_owner, ach::DataModel *_base);
		~BodySimple();

		void flip();
		void reset();
	};
}

#endif
