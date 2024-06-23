#ifndef __CHARACTER_BODY_HUMANOID
#define __CHARACTER_BODY_HUMANOID


namespace ach
{
	struct BodyHumanoid : Body
	{
		ach::BodyPart *body;
		ach::BodyPart *legs;

		 BodyHumanoid(ach::Character *_owner, ach::DataBody *_base);
		~BodyHumanoid();
	};
}

#endif
