#ifndef __PROCESS_CUTSCENE
#define __PROCESS_CUTSCENE


namespace ach
{
	struct ProcessCutscene : Process
	{
		ach::DataCutscene *base;


		 ProcessCutscene(ach::StateGame *_owner, ach::DataCutscene *cutscene);
		~ProcessCutscene();

		void update();
		void render();

		void event(sf::Event e);
	};
}

#endif
