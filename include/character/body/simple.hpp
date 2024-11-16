#ifndef __CHARACTER_BODY_SIMPLE
#define __CHARACTER_BODY_SIMPLE


namespace ach
{
	struct BodySimple : Body
	{
		ach::BodyPart *body;

		 BodySimple(ach::Character *_owner, ach::DataBody *_base);
		~BodySimple();

		void reset();
	};
}

#endif
