#ifndef __FRAMEWORK_MANAGER_TIME
#define __FRAMEWORK_MANAGER_TIME


namespace ach
{
	enum TimeSource
	{
		tsReal,
		tsFrame
	};


	struct TimeManager
	{
		sf::Clock *clock;

		long       last;
		float      frame;
		float      real;
		float      passed;


		 TimeManager();
		~TimeManager();

		void init();
		void update();
		void pause();

		float get(ach::TimeSource source);
	};
}

#endif
