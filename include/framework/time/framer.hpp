#ifndef __FRAMEWORK_TIME_FRAMER
#define __FRAMEWORK_TIME_FRAMER


namespace ach
{
	struct Framer
	{
		unsigned int frame;
		float        value;
		float        timer;


		 Framer(float _timer);
		~Framer();

		void update(bool real = false);
		void reset();
	};
}

#endif
