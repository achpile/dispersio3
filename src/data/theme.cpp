#include "meta/headers.hpp"


/***********************************************************************
     * DataTheme
     * constructor

***********************************************************************/
ach::DataTheme::DataTheme(json_t *obj)
{
	box.border      = str_to_color(json_object_get_branch_string(obj, "Box.Border"));
	box.color       = str_to_color(json_object_get_branch_string(obj, "Box.Color" ));
	box.round       = json_object_get_branch_boolean(obj, "Box.Round");

	arcade.font     = db->getFont (json_object_get_branch_string(obj, "Arcade.Font" ))->font;
	arcade.color    = str_to_color(json_object_get_branch_string(obj, "Arcade.Color"));
	arcade.size     = json_object_get_branch_integer(obj, "Arcade.Size");

	credits.font    = db->getFont (json_object_get_branch_string(obj, "Credits.Font" ))->font;
	credits.color   = str_to_color(json_object_get_branch_string(obj, "Credits.Color"));
	credits.size    = json_object_get_branch_integer(obj, "Credits.Size");

	cutscene.font   = db->getFont (json_object_get_branch_string(obj, "Cutscene.Font" ))->font;
	cutscene.color  = str_to_color(json_object_get_branch_string(obj, "Cutscene.Color"));
	cutscene.size   = json_object_get_branch_integer(obj, "Cutscene.Size");

	menu.text.font  = db->getFont (json_object_get_branch_string(obj, "Menu.Text.Font" ))->font;
	menu.text.color = str_to_color(json_object_get_branch_string(obj, "Menu.Text.Color"));
	menu.text.size  = json_object_get_branch_integer(obj, "Menu.Text.Size"   );

	menu.selector   = str_utf8    (json_object_get_branch_string(obj, "Menu.Selector"  ));

	menu.blip       = db->getSound(json_object_get_branch_string(obj, "Menu.Sound.Blip"));
	menu.back       = db->getSound(json_object_get_branch_string(obj, "Menu.Sound.Back"));
	menu.pick       = db->getSound(json_object_get_branch_string(obj, "Menu.Sound.Pick"));
}



/***********************************************************************
     * DataTheme
     * destructor

***********************************************************************/
ach::DataTheme::~DataTheme()
{
}
