#ifndef __PROCESS_BASE
#define __PROCESS_BASE


namespace ach
{
	struct Process
	{
		         Process()            {};
		virtual ~Process()            {};

		virtual void update()         {};
		virtual void render()         {};
		virtual void event(sf::Event) {};
	};
}

#endif
