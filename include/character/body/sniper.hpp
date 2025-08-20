#ifndef __CHARACTER_BODY_SNIPER
#define __CHARACTER_BODY_SNIPER


namespace ach
{
	struct BodySniper : Body
	{
		 BodySniper(ach::Character *_owner, ach::DataModel *_base);
		~BodySniper();

		void flip();
		void reset();
	};
}

#endif
