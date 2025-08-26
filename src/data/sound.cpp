#include "meta/headers.hpp"


/***********************************************************************
     * DataSound
     * constructor

***********************************************************************/
ach::DataSound::DataSound(json_t *obj)
{
	sfml_load_sound(&snd, json_string_value(obj));
}



/***********************************************************************
     * DataSound
     * destructor

***********************************************************************/
ach::DataSound::~DataSound()
{
	delete snd;
}
