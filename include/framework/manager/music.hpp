#ifndef __FRAMEWORK_MANAGER_MUSIC
#define __FRAMEWORK_MANAGER_MUSIC


namespace ach
{
	struct MusicManager
	{
		sf::Music *track;

		char current[STR_LEN_PATH];


		 MusicManager();
		~MusicManager();

		void play(const char *name);

		void volume();
	};
}

#endif
