#include "meta/headers.hpp"


/***********************************************************************
     * Theme
     * constructor

***********************************************************************/
ach::Theme::Theme()
{
}



/***********************************************************************
     * Theme
     * destructor

***********************************************************************/
ach::Theme::~Theme()
{
}



/***********************************************************************
     * Theme
     * refresh

***********************************************************************/
void ach::Theme::refresh()
{
	ach::DataTheme *base = db->getTheme(settings->getTheme());

	credits        = &base->credits;
	cutscene       = &base->cutscene;
	menu.text      = &base->menu.text;
	menu.box       = &base->box;

	menu.back     = base->menu.back->snd;
	menu.blip     = base->menu.blip->snd;
	menu.pick     = base->menu.pick->snd;

	menu.selector = base->menu.selector;
}
