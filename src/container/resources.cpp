#include "meta/headers.hpp"


/***********************************************************************
     * Resources
     * constructor

***********************************************************************/
ach::Resources::Resources()
{
	sfml_load_font(&fonts.menu   , json_object_get_branch_string(dm->data, "Meta.Font.Menu"   ));
	sfml_load_font(&fonts.credits, json_object_get_branch_string(dm->data, "Meta.Font.Credits"));

	sfml_load_sound(&sound.blip  , json_object_get_branch_string(dm->data, "Meta.Sound.Menu.Blip"));
	sfml_load_sound(&sound.back  , json_object_get_branch_string(dm->data, "Meta.Sound.Menu.Back"));
	sfml_load_sound(&sound.pick  , json_object_get_branch_string(dm->data, "Meta.Sound.Menu.Pick"));

	sfml_load_image(&meta.icon   , json_object_get_branch_string(dm->data, "Meta.Icon"));
}



/***********************************************************************
     * Resources
     * destructor

***********************************************************************/
ach::Resources::~Resources()
{
	delete fonts.menu;
	delete fonts.credits;

	delete sound.blip;
	delete sound.back;
	delete sound.pick;

	delete meta.icon;
}
