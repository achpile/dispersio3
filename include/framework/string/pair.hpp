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


const char *pair_get_string(int val, ach::Pair pairs[]);
int         pair_get_enum(const char *val, ach::Pair pairs[]);

#endif
