#include "meta/headers.hpp"


/***********************************************************************
     * MusicManager
     * constructor

***********************************************************************/
ach::MusicManager::MusicManager()
{
	track      = new sf::Music();
	current[0] = 0;

	fader.set(TIME_MUSIC_FADE);

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
	fader.update(true);
	fade();
}



/***********************************************************************
     * MusicManager
     * play

***********************************************************************/
void ach::MusicManager::play(const char *name, bool loop, bool reset)
{
	if (strcmp(current, name) == 0)
		return;

	strncpy(current, name, STR_LEN_PATH);

	sf::Time offset = sf::milliseconds(floor(track->getPlayingOffset().asSeconds()) * 1000);

	track->stop();
	track->openFromFile(current);
	track->setLoop(loop);
	track->play();

	if (reset)
		fader.reset();
	else
		track->setPlayingOffset(offset);

	fade();
}



/***********************************************************************
     * MusicManager
     * fade

***********************************************************************/
void ach::MusicManager::fade()
{
	if (fader.active()) track->setVolume(vol * fader.progress());
	else                track->setVolume(vol);
}



/***********************************************************************
     * MusicManager
     * volume

***********************************************************************/
void ach::MusicManager::volume()
{
	vol = settings->getVolumeMusic();
}
