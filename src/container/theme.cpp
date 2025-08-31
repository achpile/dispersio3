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

	credits.font  = base->credits.font->font;
	credits.size  = base->credits.size;
	credits.color = base->credits.color;

	menu.font     = base->menu.font->font;
	menu.size     = base->menu.size;
	menu.color    = base->menu.color;
	menu.selector = base->menu.selector;

	menu.border   = base->box.border;
	menu.bg       = base->box.bg;
	menu.round    = base->box.round;

	menu.back     = base->menu.back->snd;
	menu.blip     = base->menu.blip->snd;
	menu.pick     = base->menu.pick->snd;

	menu.spacing  = menu.font->getLineSpacing(menu.size);
}
