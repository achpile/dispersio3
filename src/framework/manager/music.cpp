#include "meta/headers.hpp"


/***********************************************************************
     * MusicManager
     * constructor

***********************************************************************/
ach::MusicManager::MusicManager()
{
	track = new sf::Music();
	track->setLoop(true);

	fade.set(TIME_MUSIC_FADE);

	current[0] = 0;
	vol        = 100;
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
     * update

***********************************************************************/
void ach::MusicManager::update()
{
	fade.update(true);

	if (fade.isActive()) track->setVolume(vol * math_sqr(fade.progress()));
	else                 track->setVolume(vol);
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

	fade.reset();

	track->stop();
	track->setVolume(0);
	track->openFromFile(current);
	track->play();
}



/***********************************************************************
     * MusicManager
     * volume

***********************************************************************/
void ach::MusicManager::volume()
{
	vol = settings->getVolumeMusic();
}
