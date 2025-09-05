#ifndef __PROCESS_PROCESS
#define __PROCESS_PROCESS


namespace ach
{
	struct Process
	{
		ach::StateGame *owner;

		bool active;


		         Process(ach::StateGame *_owner);
		virtual ~Process();

		virtual void update()         {};
		virtual void render()         {};
		virtual void event(sf::Event) {};

		virtual void translate()      {};
		virtual void style()          {};

		virtual void refresh()        {};
	};
}

#endif
