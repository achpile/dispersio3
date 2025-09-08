#ifndef __FRAMEWORK_TIME_PULSE
#define __FRAMEWORK_TIME_PULSE


namespace ach
{
	struct Pulse
	{
		float value;
		float timer;
		bool  active;


		 Pulse();
		~Pulse();

		void  set(float _timer);
		void  reset();
		bool  update(bool real = false);
	};
}

#endif
