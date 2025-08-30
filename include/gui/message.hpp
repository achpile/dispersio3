#ifndef __GUI_MESSAGE
#define __GUI_MESSAGE


namespace ach
{
	struct Message
	{
		ach::RectangleShape *box;
		ach::Text           *text;


		 Message();
		~Message();

		void render();

		void style();
	};
}

#endif
