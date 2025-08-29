#include "meta/headers.hpp"


/***********************************************************************
     * Settings
     * constructor

***********************************************************************/
ach::Settings::Settings()
{
	data = json_object_get(dm->data, "Settings");
}



/***********************************************************************
     * Settings
     * destructor

***********************************************************************/
ach::Settings::~Settings()
{
	if (data)
		json_dump_file(data, FILE_SETTINGS, JSON_INDENT(4) | JSON_SORT_KEYS);
}



/***********************************************************************
     * Settings
     * isFullscreen

***********************************************************************/
bool ach::Settings::isFullscreen()
{
	return json_object_get_branch_boolean(data, "Window.Fullscreen");
}



/***********************************************************************
     * Settings
     * isSmooth

***********************************************************************/
bool ach::Settings::isSmooth()
{
	return json_object_get_branch_boolean(data, "Window.Smooth");
}



/***********************************************************************
     * Settings
     * isCutscenes

***********************************************************************/
bool ach::Settings::isCutscenes()
{
	return json_object_get_branch_boolean(data, "Game.Cutscenes");
}



/***********************************************************************
     * Settings
     * getLanguage

***********************************************************************/
const char* ach::Settings::getLanguage()
{
	return json_object_get_branch_string(data, "Game.Language");
}



/***********************************************************************
     * Settings
     * getTheme

***********************************************************************/
const char* ach::Settings::getTheme()
{
	return json_object_get_branch_string(data, "Game.Theme");
}



/***********************************************************************
     * Settings
     * getVolumeSound

***********************************************************************/
int ach::Settings::getVolumeSound()
{
	return json_object_get_branch_integer(data, "Audio.Sound") * 10;
}



/***********************************************************************
     * Settings
     * getVolumeMusic

***********************************************************************/
int ach::Settings::getVolumeMusic()
{
	return json_object_get_branch_integer(data, "Audio.Music") * 10;
}



/***********************************************************************
     * Settings
     * getFrameRate

***********************************************************************/
int ach::Settings::getFrameRate()
{
	return json_object_get_branch_integer(data, "Window.FrameRate");
}



/***********************************************************************
     * Settings
     * getWindowMode

***********************************************************************/
sf::VideoMode ach::Settings::getWindowMode()
{
	if (isFullscreen())
		return sf::VideoMode::getDesktopMode();


	return sf::VideoMode(json_object_get_branch_integer(data, "Window.Width" ),
	                     json_object_get_branch_integer(data, "Window.Height"),
	                     32);
}



/***********************************************************************
     * Settings
     * getWindowStyle

***********************************************************************/
sf::Uint32 ach::Settings::getWindowStyle()
{
	if (isFullscreen()) return sf::Style::Fullscreen;
	else                return sf::Style::Default;
}



/***********************************************************************
     * Settings
     * getWindowPosition

***********************************************************************/
sf::Vector2i ach::Settings::getWindowPosition()
{
	if (isFullscreen())
		return sf::Vector2i(0, 0);

	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::Vector2i  offset;

	offset.x = (desktop.width  - json_object_get_branch_integer(data, "Window.Width" )) / 2;
	offset.y = (desktop.height - json_object_get_branch_integer(data, "Window.Height")) / 2;

	if (offset.x < 0)
		offset.x = 0;

	if (offset.y < 0)
		offset.y = 0;

	return offset;
}



/***********************************************************************
     * Settings
     * setWindowSize

***********************************************************************/
void ach::Settings::setWindowSize(sf::Vector2u size)
{
	if (isFullscreen())
		return;

	json_object_set_branch_integer(data, "Window.Width" , size.x);
	json_object_set_branch_integer(data, "Window.Height", size.y);
}



/***********************************************************************
     * Settings
     * listRates

***********************************************************************/
json_t* ach::Settings::listRates()
{
	json_t *res = json_array();

	json_array_append_new(res, json_pack("{s:s, s:i, s:b}", "Name", "UI.Menu.Misc.Off", "Value", 0  , "Token", true ));
	json_array_append_new(res, json_pack("{s:s, s:i, s:b}", "Name", "60"              , "Value", 60 , "Token", false));
	json_array_append_new(res, json_pack("{s:s, s:i, s:b}", "Name", "120"             , "Value", 120, "Token", false));
	json_array_append_new(res, json_pack("{s:s, s:i, s:b}", "Name", "144"             , "Value", 144, "Token", false));
	json_array_append_new(res, json_pack("{s:s, s:i, s:b}", "Name", "240"             , "Value", 240, "Token", false));

	return res;
}



/***********************************************************************
     * Settings
     * getKeyCode

***********************************************************************/
sf::Keyboard::Key ach::Settings::getKeyCode(ach::ControlAction action)
{
	return pair_get_enum(json_object_getv_branch_string(data, "Control.%s.Key", pair_get_string(action, pairAction)), pairKey);
}



/***********************************************************************
     * Settings
     * getJoyCode

***********************************************************************/
ach::JoystickCode ach::Settings::getJoyCode(ach::ControlAction action)
{
	return pair_get_enum(json_object_getv_branch_string(data, "Control.%s.Joy", pair_get_string(action, pairAction)), pairJoy);
}



/***********************************************************************
     * Settings
     * setKeyCode

***********************************************************************/
void ach::Settings::setKeyCode(ach::ControlAction action, sf::Keyboard::Key code)
{
	json_object_setv_branch_string(data, pair_get_string(code, pairKey), "Control.%s.Key", pair_get_string(action, pairAction));
}



/***********************************************************************
     * Settings
     * setJoyCode

***********************************************************************/
void ach::Settings::setJoyCode(ach::ControlAction action, ach::JoystickCode code)
{
	json_object_setv_branch_string(data, pair_get_string(code, pairJoy), "Control.%s.Joy", pair_get_string(action, pairAction));
}
