#ifndef __FRAMEWORK_STRING_OPTION
#define __FRAMEWORK_STRING_OPTION


namespace ach
{
	struct Option
	{
		sf::String  caption;
		json_t     *value;

		char        name[STR_LEN_MENU];
		bool        token;


		 Option(json_t *obj);
		~Option();
	};
}

#endif
