#include "meta/headers.hpp"


/***********************************************************************
     * SoundManager
     * constructor

***********************************************************************/
ach::SoundManager::SoundManager()
{
	track = new sf::Music();
	track->setLoop(true);

	volume();
}



/***********************************************************************
     * SoundManager
     * destructor

***********************************************************************/
ach::SoundManager::~SoundManager()
{
	list_delete(sound);

	delete track;
}



/***********************************************************************
     * SoundManager
     * update

***********************************************************************/
void ach::SoundManager::update()
{
	std::sort(buf.begin(), buf.end());
	buf.erase(std::unique(buf.begin(), buf.end()), buf.end());

	add();

	for (unsigned int i = 0; i < sound.size();)
	{
		if (sound[i]->getStatus() == sf::Sound::Stopped)
		{
			delete sound[i];
			sound.erase(sound.begin() + i);

			continue;
		}

		i++;
	}
}



/***********************************************************************
     * SoundManager
     * play

***********************************************************************/
void ach::SoundManager::play(sf::SoundBuffer *sfx)
{
	if (sfx)
		buf.push_back(sfx);
}



/***********************************************************************
     * SoundManager
     * add

***********************************************************************/
void ach::SoundManager::add()
{
	while (!buf.empty())
	{
		sf::Sound *sfx = new sf::Sound();

		sfx->setBuffer(*buf.back());
		sfx->setVolume(settings->getVolumeSound());
		sfx->play();

		sound.push_back(sfx);
		buf.pop_back();
	}
}



/***********************************************************************
     * SoundManager
     * volume

***********************************************************************/
void ach::SoundManager::volume()
{
	track->setVolume(settings->getVolumeMusic());
}
