#ifndef __CHARACTER_AI_CRAWL
#define __CHARACTER_AI_CRAWL


namespace ach
{
	struct AICrawl : AI
	{
		 AICrawl(ach::Character *_owner, json_t *obj);
		~AICrawl();

		void control();

		void collide(ach::PhysLine *line);
	};
}

#endif
