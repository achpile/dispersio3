#include "meta/headers.hpp"


/***********************************************************************
     * DataTheme
     * constructor

***********************************************************************/
ach::DataTheme::DataTheme(json_t *obj)
{
	credits.font  = db->getFont (json_object_get_branch_string(obj, "Credits.Font.Name" ));
	credits.color = str_to_color(json_object_get_branch_string(obj, "Credits.Font.Color"));

	menu.selector = str_utf8    (json_object_get_branch_string(obj, "Menu.Selector"  ));
	menu.font     = db->getFont (json_object_get_branch_string(obj, "Menu.Font.Name" ));
	menu.color    = str_to_color(json_object_get_branch_string(obj, "Menu.Font.Color"));

	menu.blip     = db->getSound(json_object_get_branch_string(obj, "Menu.Sound.Blip"));
	menu.back     = db->getSound(json_object_get_branch_string(obj, "Menu.Sound.Back"));
	menu.pick     = db->getSound(json_object_get_branch_string(obj, "Menu.Sound.Pick"));

	box.border    = str_to_color(json_object_get_branch_string(obj, "Box.Color"     ));
	box.bg        = str_to_color(json_object_get_branch_string(obj, "Box.Background"));

	box.round     = json_object_get_branch_boolean(obj, "Box.Round");

	credits.size  = json_object_get_branch_integer(obj, "Credits.Font.Size");
	menu.size     = json_object_get_branch_integer(obj, "Menu.Font.Size"   );
}



/***********************************************************************
     * DataTheme
     * destructor

***********************************************************************/
ach::DataTheme::~DataTheme()
{
}
