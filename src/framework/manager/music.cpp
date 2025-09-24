#include "meta/headers.hpp"


/***********************************************************************
     * MusicManager
     * constructor

***********************************************************************/
ach::MusicManager::MusicManager()
{
	track      = new sf::Music();
	current[0] = 0;

	fade.set(TIME_MUSIC_FADE);

	volume();
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
void ach::MusicManager::play(const char *name, bool loop)
{
	if (strcmp(current, name) == 0)
		return;

	strncpy(current, name, STR_LEN_PATH);

	fade.reset();

	track->stop();
	track->setVolume(0);
	track->setLoop(loop);
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
