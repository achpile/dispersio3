#ifndef __FRAMEWORK_TIME_FRAMER
#define __FRAMEWORK_TIME_FRAMER


namespace ach
{
	struct Framer
	{
		float value;
		float timer;


		 Framer();
		~Framer();

		void set(float _timer);
		void reset();
		void zero();
		int  update(bool real = false);
	};
}

#endif
