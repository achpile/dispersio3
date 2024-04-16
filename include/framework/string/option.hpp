#ifndef __FRAMEWORK_STRING_OPTION
#define __FRAMEWORK_STRING_OPTION


namespace ach
{
	struct Option
	{
		sf::String caption;
		char       value[STR_LEN_MENU];


		 Option(sf::String _caption, char *_value);
		~Option();
	};
}

#endif
