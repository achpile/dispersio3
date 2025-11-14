#ifndef __FRAMEWORK_MISC_SCORE
#define __FRAMEWORK_MISC_SCORE


namespace ach
{
	struct Score
	{
		int value;
		int csum;


		 Score();
		~Score();

		void reset();
		bool check();
		void increase();
		void add(int score);
		void set(int score);

		int  sum();
		int  get();
	};
}

#endif
