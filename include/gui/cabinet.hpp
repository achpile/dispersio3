#ifndef __GUI_CABINET
#define __GUI_CABINET


namespace ach
{
	struct Cabinet
	{
		std::vector<ach::ArcadeGame> games;

		ach::Arcade *game;
		ach::Sprite *cabinet;

		int index;


		 Cabinet();
		~Cabinet();

		void update();
		void render();

		void init(bool menu);
		void load(bool menu);
		void select(int offset);

		void controls();
		bool active();
	};
}

#endif
