#include "meta/headers.hpp"


/***********************************************************************
     * SlideShow
     * constructor

***********************************************************************/
ach::SlideShow::SlideShow(std::vector<ach::Sprite*> *_list, bool _realtime)
{
	index    = 0;
	list     = _list;
	realtime = _realtime;
	active   = (list->size() != 0);
}



/***********************************************************************
     * SlideShow
     * destructor

***********************************************************************/
ach::SlideShow::~SlideShow()
{
}



/***********************************************************************
     * SlideShow
     * update

***********************************************************************/
void ach::SlideShow::update()
{
	if (!active)
		return;

	if (!timer.update(realtime))
		next();
}



/***********************************************************************
     * SlideShow
     * render

***********************************************************************/
void ach::SlideShow::render()
{
	if (!active)
		return;

	sf::Sprite *spr = (*list)[index]->spr;

	spr->setPosition(pos);
	spr->setColor(sf::Color(255, 255, 255, 255 * math_fade(timer.progress(), 0.25f)));

	rm->draw(spr, ach::RenderLayer::rlGUI);
}



/***********************************************************************
     * SlideShow
     * next

***********************************************************************/
void ach::SlideShow::next()
{
	index++;

	timer.reset();

	if (index >= list->size())
		active = false;
}



/***********************************************************************
     * SlideShow
     * setPosition

***********************************************************************/
void ach::SlideShow::setPosition(sf::Vector2f _pos)
{
	pos = _pos;
}



/***********************************************************************
     * SlideShow
     * setDuration

***********************************************************************/
void ach::SlideShow::setDuration(float duration)
{
	timer.set(duration);
}
