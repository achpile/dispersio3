#ifndef __STATE_START
#define __STATE_START


namespace ach
{
	struct StateStart : StateBase
	{
		std::vector<ach::Sprite*>  sprites;

		ach::SlideShow            *slideshow;


		 StateStart();
		~StateStart();

		void update();
		void render();
		void event(sf::Event);
	};
}

#endif
