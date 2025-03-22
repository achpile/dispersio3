#ifndef __FRAMEWORK_MANAGER_LANGUAGE
#define __FRAMEWORK_MANAGER_LANGUAGE


namespace ach
{
	struct LanguageManager
	{
		json_t *data;


		 LanguageManager();
		~LanguageManager();

		sf::String get (const char *path);
		sf::String getv(const char *format, ...);

		void refresh();
	};
}

#endif
