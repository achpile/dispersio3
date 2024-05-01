#ifndef __FRAMEWORK_TIME_ANIMATION
#define __FRAMEWORK_TIME_ANIMATION


namespace ach
{
	struct Animation
	{
		ach::Framer framer;

		int  frame;

		int  start;
		int  end;
		bool loop;


		 Animation();
		~Animation();

		void update();
		void reset();

		void set(int _start, int _end, bool _loop, float rate, int frames);
		void set(json_t *obj, int frames);
	};
}

#endif
