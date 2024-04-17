#ifndef __STATE_START
#define __STATE_START


namespace ach
{
	struct StateStart : StateBase
	{
		std::vector<ach::Sprite*> sprites;

		unsigned int index;
		float        offset;


		 StateStart();
		~StateStart();

		void update();
		void render();
		void event(sf::Event);

		void next();
	};
}

#endif
