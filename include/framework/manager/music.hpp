#ifndef __FRAMEWORK_MANAGER_MUSIC
#define __FRAMEWORK_MANAGER_MUSIC


namespace ach
{
	struct MusicManager
	{
		ach::Timer  fade;
		sf::Music  *track;

		int  vol;
		char current[STR_LEN_PATH];


		 MusicManager();
		~MusicManager();

		void update();
		void play(const char *name, bool loop);

		void volume();
	};
}

#endif
