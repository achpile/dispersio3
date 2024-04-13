#ifndef __FRAMEWORK_TIME_TIMER
#define __FRAMEWORK_TIME_TIMER


namespace ach
{
	struct Timer
	{
		float value;
		float timer;


		 Timer(float _timer = 0.0f);
		~Timer();

		void  set(float _timer);
		void  reset();
		bool  update(bool real = false);
		bool  isActive();
	};
}

#endif
