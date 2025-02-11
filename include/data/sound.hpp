#ifndef __DATA_SOUND
#define __DATA_SOUND


namespace ach
{
	struct DataSound : DataContent
	{
		sf::SoundBuffer *snd;

		 DataSound(json_t *obj);
		~DataSound();
	};
}

#endif
