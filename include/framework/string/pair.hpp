#ifndef __FRAMEWORK_STRING_PAIR
#define __FRAMEWORK_STRING_PAIR


namespace ach
{
	template <typename T>
	struct Pair
	{
		T           num;
		const char *str;
	};
}


template <typename T> const char *pair_get_string(T val, ach::Pair<T> pairs[]);
template <typename T> T           pair_get_enum(const char *val, ach::Pair<T> pairs[]);
template <typename T> bool        pair_has_enum(T val, ach::Pair<T> pairs[]);

#endif
