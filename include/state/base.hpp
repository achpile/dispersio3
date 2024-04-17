#ifndef __STATE_BASE
#define __STATE_BASE


namespace ach
{
	struct StateBase
	{
		         StateBase()          {};
		virtual ~StateBase()          {};

		virtual void update()         {};
		virtual void render()         {};
		virtual void translate()      {};
		virtual void event(sf::Event) {};
	};
}

#endif
