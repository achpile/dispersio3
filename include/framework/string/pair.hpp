#ifndef __FRAMEWORK_STRING_PAIR
#define __FRAMEWORK_STRING_PAIR


namespace ach
{
	struct Pair
	{
		int         num;
		const char *str;
	};
}


const char *pairGetString(int val, ach::Pair pairs[]);
int         pairGetEnum(const char *val, ach::Pair pairs[]);

#endif
