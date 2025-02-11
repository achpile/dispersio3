#include "meta/headers.hpp"


/***********************************************************************
     * DataSound
     * constructor

***********************************************************************/
ach::DataSound::DataSound(json_t *obj)
{
	sfml_load_sound(&snd, json_object_get_string(obj, "Filename"));
}



/***********************************************************************
     * DataSound
     * destructor

***********************************************************************/
ach::DataSound::~DataSound()
{
	delete snd;
}
