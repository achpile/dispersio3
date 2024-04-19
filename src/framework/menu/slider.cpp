#include "meta/headers.hpp"


/***********************************************************************
     * MenuItemSlider
     * constructor

***********************************************************************/
ach::MenuItemSlider::MenuItemSlider(ach::Menu *_menu, const char *_name, ach::Handler _handler, json_t *_data, int _min, int _max) : MenuItem(_menu, _name)
{
	min     = _min;
	max     = _max;
	data    = _data;
	handler = _handler;

	box  = new sf::RectangleShape();
	fill = new sf::RectangleShape();

	box->setSize(sf::Vector2f(menu->size * MENU_SLIDER_SIZE, menu->size));
	box->setOrigin(menu->size * MENU_SLIDER_SIZE, 0);
	box->setFillColor(sf::Color::Transparent);
	box->setOutlineThickness(MENU_THICKNESS);
	box->setOutlineColor(menu->text->getFillColor());

	fill->setOrigin(menu->size * MENU_SLIDER_SIZE - MENU_BOX_SHRINK / 2, - MENU_BOX_SHRINK / 2);
	fill->setFillColor(menu->box->getOutlineColor());
}



/***********************************************************************
     * MenuItemSlider
     * destructor

***********************************************************************/
ach::MenuItemSlider::~MenuItemSlider()
{
	delete box;
	delete fill;
}



/***********************************************************************
     * MenuItemSlider
     * action

***********************************************************************/
void ach::MenuItemSlider::action(int d)
{
	if (!interval_check(value + d, min, max))
		return;

	value += d;

	json_integer_set(data, value);
	sm->play(menu->sfxPick);
}



/***********************************************************************
     * MenuItemSlider
     * render

***********************************************************************/
void ach::MenuItemSlider::render(int i)
{
	box->setPosition (menu->right(), menu->line(i));
	fill->setPosition(menu->right(), menu->line(i));

	fill->setSize(sf::Vector2f((menu->size * MENU_SLIDER_SIZE - MENU_BOX_SHRINK) * (value - min) / (max - min), menu->size - MENU_BOX_SHRINK));

	rm->draw(box , ach::RenderLayer::rlGUI);
	rm->draw(fill, ach::RenderLayer::rlGUI);
}



/***********************************************************************
     * MenuItemSlider
     * finalize

***********************************************************************/
void ach::MenuItemSlider::finalize()
{
	value = json_integer_value(data);
}



/***********************************************************************
     * MenuItemSlider
     * left

***********************************************************************/
void ach::MenuItemSlider::left()
{
	action(-1);
}



/***********************************************************************
     * MenuItemSlider
     * right

***********************************************************************/
void ach::MenuItemSlider::right()
{
	action(1);
}



/***********************************************************************
     * MenuItemSlider
     * click

***********************************************************************/
void ach::MenuItemSlider::click()
{
	action(1);
}



/***********************************************************************
     * MenuItemSlider
     * rclick

***********************************************************************/
void ach::MenuItemSlider::rclick()
{
	action(-1);
}
