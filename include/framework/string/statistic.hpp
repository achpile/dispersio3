#ifndef __FRAMEWORK_STRING_STATISTIC
#define __FRAMEWORK_STRING_STATISTIC


namespace ach
{
	struct Statistic
	{
		sf::String caption;
		sf::String value;

		Statistic(sf::String _caption, sf::String _value);
	};
}

#endif
