#ifndef __CHARACTER_AI_BASE
#define __CHARACTER_AI_BASE


namespace ach
{
	struct AI
	{
		ach::Character *owner;


		         AI(ach::Character *_owner);
		virtual ~AI();

		void update();

		virtual void control() {};
		virtual void aim()     {};

		static ach::AI *create(ach::Character *_owner, ach::AIType type);
	};
}

#endif
