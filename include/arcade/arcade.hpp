#ifndef __ARCADE_ARCADE
#define __ARCADE_ARCADE


namespace ach
{
	struct Arcade
	{
		bool active;


		         Arcade();
		virtual ~Arcade();

		void update();
		void render();

		void controls();

		virtual void process() {};
		virtual void draw()    {};
		virtual void handle()  {};

		static ach::Arcade* create();
	};
}

#endif
