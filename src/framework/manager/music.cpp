#include "meta/headers.hpp"


/***********************************************************************
     * MusicManager
     * constructor

***********************************************************************/
ach::MusicManager::MusicManager()
{
	track = new sf::Music();
	track->setLoop(true);

	current[0] = 0;
}



/***********************************************************************
     * MusicManager
     * destructor

***********************************************************************/
ach::MusicManager::~MusicManager()
{
	delete track;
}



/***********************************************************************
     * MusicManager
     * play

***********************************************************************/
void ach::MusicManager::play(const char *name)
{
	if (strcmp(current, name) == 0)
		return;

	strncpy(current, name, STR_LEN_PATH);

	track->stop();
	track->openFromFile(current);
	track->play();
}



/***********************************************************************
     * MusicManager
     * volume

***********************************************************************/
void ach::MusicManager::volume()
{
	track->setVolume(settings->getVolumeMusic());
}
