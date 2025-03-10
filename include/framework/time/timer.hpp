#ifndef __FRAMEWORK_TIME_TIMER
#define __FRAMEWORK_TIME_TIMER


namespace ach
{
	struct Timer
	{
		float value;
		float timer;


		 Timer();
		~Timer();

		void set(float _timer);
		void reset();
		void zero();
		bool update(ach::TimeSource source = ach::TimeSource::tsFrame);
		bool isActive();
	};
}

#endif
