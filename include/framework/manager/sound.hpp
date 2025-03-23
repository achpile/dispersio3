#ifndef __FRAMEWORK_MANAGER_SOUND
#define __FRAMEWORK_MANAGER_SOUND


namespace ach
{
	struct SoundManager
	{
		std::vector<sf::Sound*>       sound;
		std::vector<sf::SoundBuffer*> buf;


		 SoundManager();
		~SoundManager();

		void update();
		void add();
		void play(sf::SoundBuffer *sfx);

		void volume();
	};
}

#endif
