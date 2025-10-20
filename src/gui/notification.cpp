#include "meta/headers.hpp"


/***********************************************************************
     * Notification
     * constructor

***********************************************************************/
ach::Notification::Notification()
{
	box   = new ach::RectangleShape();
	text  = new sf::Text();

	offset = sf::Vector2f(GUI_NOTIFICATION_Y / 2.0f, GUI_NOTIFICATION_Y / 2.0f);

	box->setOutlineThickness(MENU_THICKNESS);
	box->setSize(sf::Vector2f(GUI_NOTIFICATION_X, GUI_NOTIFICATION_Y));

	timer.set(4.0f);
	timer.zero();
}



/***********************************************************************
     * Notification
     * destructor

***********************************************************************/
ach::Notification::~Notification()
{
	delete box;
	delete text;
}



/***********************************************************************
     * Notification
     * update

***********************************************************************/
void ach::Notification::update()
{
	if (!timer.active())
	{
		next();
		return;
	}

	timer.update(true);

	pos = sf::Vector2f(RENDER_LAYER_GUI_X - GUI_NOTIFICATION_X - 5.0f, RENDER_LAYER_GUI_Y - GUI_NOTIFICATION_Y - 5.0f);

	if (timer.value < 0.5f)
		pos.x += (0.5 - timer.value) * 2.0f * (GUI_NOTIFICATION_X + 5.0f);

	if (timer.value > 3.5f)
		pos.y += (timer.value - 3.5f) * 2.0f * (GUI_NOTIFICATION_Y + 5.0f);

	render();
}



/***********************************************************************
     * Notification
     * render

***********************************************************************/
void ach::Notification::render()
{
	box->setPosition(pos);
	spr->spr->setPosition(pos + offset);

	rm->draw(box     , ach::RenderLayer::rlGUI);
	rm->draw(spr->spr, ach::RenderLayer::rlGUI);

	text_draw(text, caption, pos.x + GUI_NOTIFICATION_Y + 10.0f, pos.y + 10.0f                    , 0, ach::TextAlign::taLeft, ach::RenderLayer::rlGUI);
	text_draw(text, name   , pos.x + GUI_NOTIFICATION_Y + 10.0f, pos.y + GUI_NOTIFICATION_Y / 2.0f, 0, ach::TextAlign::taLeft, ach::RenderLayer::rlGUI);
}



/***********************************************************************
     * Notification
     * style

***********************************************************************/
void ach::Notification::style()
{
	box->style(theme->menu.box);

	text->setCharacterSize(theme->menu.text->size);
	text->setFont(*theme->menu.text->font);
	text->setFillColor(theme->menu.text->color);
}



/***********************************************************************
     * Notification
     * translate

***********************************************************************/
void ach::Notification::translate()
{
	caption = lm->get("UI.Stats.Unlock");
}



/***********************************************************************
     * Notification
     * init

***********************************************************************/
void ach::Notification::init()
{
	sfx = db->getSound(json_object_get_branch_string(dm->data, "Meta.SFX.Achievement"));

	style();
	translate();
}



/***********************************************************************
     * Notification
     * next

***********************************************************************/
void ach::Notification::next()
{
	if (!list.size())
		return;

	spr  = db->getSprite(json_object_getv_branch_string(dm->data, "Meta.GFX.Achievement.%s", pair_get_string(list[0], pairAchievement)))->spr;
	name = lm->getv("UI.Achievement.%s.Name", pair_get_string(list[0], pairAchievement));

	sm->play(sfx->snd);
	list.erase(list.begin());
	timer.reset();
}



/***********************************************************************
     * Notification
     * trigger

***********************************************************************/
void ach::Notification::trigger(ach::Achievement achievement)
{
	list.push_back(achievement);
}
