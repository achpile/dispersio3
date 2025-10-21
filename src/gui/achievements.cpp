#include "meta/headers.hpp"


/***********************************************************************
     * Achievements
     * constructor

***********************************************************************/
ach::Achievements::Achievements()
{
	box    = new ach::RectangleShape();
	text   = new sf::Text();

	active = false;
	pos    = sf::Vector2f((RENDER_LAYER_GUI_X - GUI_ACHIEVEMENT_W) / 2.0f, GUI_ACHIEVEMENT_Y);

	box->setOutlineThickness(MENU_THICKNESS);
	box->setSize(sf::Vector2f(GUI_ACHIEVEMENT_W, GUI_ACHIEVEMENT_H));
	box->setPosition(pos);

	style();
	translate();
}



/***********************************************************************
     * Achievements
     * destructor

***********************************************************************/
ach::Achievements::~Achievements()
{
	delete box;
	delete text;
}



/***********************************************************************
     * Achievements
     * update

***********************************************************************/
void ach::Achievements::update()
{
}



/***********************************************************************
     * Achievements
     * render

***********************************************************************/
void ach::Achievements::render()
{
	rm->draw(box, ach::RenderLayer::rlGUI);

	text_draw(text, progress, pos.x, pos.y + 10.0f, GUI_ACHIEVEMENT_W, ach::TextAlign::taCenter, ach::RenderLayer::rlGUI);

	if (index > 0)
		text_draw(text, "...", pos.x, pos.y + GUI_ACHIEVEMENT_O / 2.0f                    , GUI_ACHIEVEMENT_W, ach::TextAlign::taCenter, ach::RenderLayer::rlGUI);

	if (index + GUI_ACHIEVEMENT_C < ach::Achievement::acCount)
		text_draw(text, "...", pos.x, pos.y - GUI_ACHIEVEMENT_O - 20.0f + GUI_ACHIEVEMENT_H, GUI_ACHIEVEMENT_W, ach::TextAlign::taCenter, ach::RenderLayer::rlGUI);

	text->setCharacterSize(theme->menu.text->size);
	text_draw(text, back, pos.x, pos.y - GUI_ACHIEVEMENT_O / 2.0f - 10.0f + GUI_ACHIEVEMENT_H, GUI_ACHIEVEMENT_W, ach::TextAlign::taCenter, ach::RenderLayer::rlGUI);

	for (int i = 0; i < GUI_ACHIEVEMENT_C; i++)
		draw(index + i, i);
}



/***********************************************************************
     * Achievements
     * event

***********************************************************************/
void ach::Achievements::event(sf::Event e)
{
	if (e.type != sf::Event::MouseButtonReleased)
		return;

	if (e.mouseButton.button != sf::Mouse::Button::Left)
		return;

	click(rm->transform(ach::RenderLayer::rlGUI, sf::Vector2f(e.mouseButton.x, e.mouseButton.y)));
}



/***********************************************************************
     * Achievements
     * translate

***********************************************************************/
void ach::Achievements::translate()
{
	back = lm->get("UI.Menu.Misc.Back");
}



/***********************************************************************
     * Achievements
     * style

***********************************************************************/
void ach::Achievements::style()
{
	box->style(theme->menu.box);

	text->setFont(*theme->menu.text->font);
	text->setFillColor(theme->menu.text->color);
}



/***********************************************************************
     * Achievements
     * controls

***********************************************************************/
void ach::Achievements::controls()
{
	if (ctrl->keys[ach::ControlAction::caUp  ].pressed) move(-1);
	if (ctrl->keys[ach::ControlAction::caDown].pressed) move( 1);
	if (ctrl->keys[ach::ControlAction::caMenu].pressed) quit();
}



/***********************************************************************
     * Achievements
     * click

***********************************************************************/
void ach::Achievements::click(sf::Vector2f c)
{
	if (sf::FloatRect(pos.x + (GUI_ACHIEVEMENT_W - 100.0f) / 2.0f, pos.y + GUI_ACHIEVEMENT_O / 2.0f                            , 100.0f, 30.0f).contains(c)) move(-1);
	if (sf::FloatRect(pos.x + (GUI_ACHIEVEMENT_W - 100.0f) / 2.0f, pos.y - GUI_ACHIEVEMENT_O        - 20.0f + GUI_ACHIEVEMENT_H, 100.0f, 30.0f).contains(c)) move( 1);
	if (sf::FloatRect(pos.x + (GUI_ACHIEVEMENT_W - 100.0f) / 2.0f, pos.y - GUI_ACHIEVEMENT_O / 2.0f - 10.0f + GUI_ACHIEVEMENT_H, 100.0f, 30.0f).contains(c)) quit();
}



/***********************************************************************
     * Achievements
     * move

***********************************************************************/
void ach::Achievements::move(int d)
{
	if (index + d < 0)
		return;

	if (index + d + GUI_ACHIEVEMENT_C > ach::Achievement::acCount)
		return;

	index += d;

	sm->play(theme->menu.blip);
}



/***********************************************************************
     * Achievements
     * quit

***********************************************************************/
void ach::Achievements::quit()
{
	active = false;

	sm->play(theme->menu.back);
}



/***********************************************************************
     * Achievements
     * init

***********************************************************************/
void ach::Achievements::init()
{
	index  = 0;
	count  = 0;
	active = true;

	const char *name;

	for (int i = 0; i < ach::Achievement::acCount; i++)
	{
		name = pair_get_string((ach::Achievement)i, pairAchievement);

		data[i].spr  = db->getSprite(json_object_getv_branch_string(dm->data, "Meta.GFX.Achievement.%s", name))->spr->spr;
		data[i].name = lm->getv("UI.Achievement.%s.Name"       , name);
		data[i].desc = lm->getv("UI.Achievement.%s.Description", name);

		if (!records->getAchievement((ach::Achievement)i))
			data[i].spr = db->getSprite(json_object_get_branch_string(dm->data, "Meta.GFX.Achievement.Locked"))->spr->spr;
		else
			count++;
	}

	progress = lm->get("UI.Stats.Progress") + " : " + std::to_string(count) + "/" + std::to_string(ach::Achievement::acCount);
}



/***********************************************************************
     * Achievements
     * draw

***********************************************************************/
void ach::Achievements::draw(int i, int y)
{
	sf::Vector2f p = sf::Vector2f(GUI_ACHIEVEMENT_S, GUI_ACHIEVEMENT_O + y * GUI_ACHIEVEMENT_S + GUI_ACHIEVEMENT_S / 2.0f);

	data[i].spr->setPosition(pos + p);

	rm->draw(data[i].spr, ach::RenderLayer::rlGUI);

	text_draw(text, data[i].name, pos.x + p.x + GUI_ACHIEVEMENT_S / 2.0f, pos.y + p.y + 10.0f - GUI_ACHIEVEMENT_S / 2.0f, 0, ach::TextAlign::taLeft, ach::RenderLayer::rlGUI);
	text_draw(text, data[i].desc, pos.x + p.x + GUI_ACHIEVEMENT_S / 2.0f, pos.y + p.y                                   , 0, ach::TextAlign::taLeft, ach::RenderLayer::rlGUI);
}
