#ifndef __GUI_NOTIFICATION
#define __GUI_NOTIFICATION


namespace ach
{
	struct Notification
	{
		std::vector<ach::Achievement> list;


		 Notification();
		~Notification();

		void update();
		void render();

		void style();

		void trigger(ach::Achievement achievement);
	};
}

#endif
