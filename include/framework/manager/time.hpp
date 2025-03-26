#ifndef __FRAMEWORK_MANAGER_TIME
#define __FRAMEWORK_MANAGER_TIME


namespace ach
{
	struct TimeManager
	{
		sf::Clock *clock;

		long long  last;
		float      frame;
		float      real;
		float      passed;


		 TimeManager();
		~TimeManager();

		void init();
		void update();
		void pause();

		float get(bool isReal = false);
	};
}

#endif
