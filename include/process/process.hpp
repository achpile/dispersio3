#ifndef __PROCESS_PROCESS
#define __PROCESS_PROCESS


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
