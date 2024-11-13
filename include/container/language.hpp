#ifndef __CONTAINER_LANGUAGE
#define __CONTAINER_LANGUAGE


namespace ach
{
	struct Language
	{
		json_t *data;


		 Language();
		~Language();

		sf::String get (const char *path);
		sf::String getv(const char *format, ...);

		void refresh();
	};
}

#endif
