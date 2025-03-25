#include "meta/headers.hpp"


/***********************************************************************
     * Menu
     * controls

***********************************************************************/
void ach::Menu::controls()
{
	if (!enabled)
		return;

	if (binding)
		return;

	if (ctrl->keys[ach::ControlAction::caUp   ].pressed) move(-1);
	if (ctrl->keys[ach::ControlAction::caDown ].pressed) move( 1);

	if (ctrl->keys[ach::ControlAction::caLeft ].pressed) current->items[index]->left();
	if (ctrl->keys[ach::ControlAction::caRight].pressed) current->items[index]->right();

	if (ctrl->keys[ach::ControlAction::caJump ].pressed) current->items[index]->pick();
	if (ctrl->keys[ach::ControlAction::caMenu ].pressed) current->items.back()->pick();
}



/***********************************************************************
     * Menu
     * inside

***********************************************************************/
bool ach::Menu::inside(sf::Vector2f v)
{
	return sf::FloatRect(pos.x, line(0), width, current->items.size() * spacing).contains(v);
}



/***********************************************************************
     * Menu
     * hover

***********************************************************************/
void ach::Menu::hover(sf::Vector2f v)
{
	if (!inside(v))
		return;

	select(floor((v.y - line(0)) / spacing));
}



/***********************************************************************
     * Menu
     * click

***********************************************************************/
void ach::Menu::click(sf::Vector2f v, bool left)
{
	if (!inside(v))
		return;

	hover(v);

	if (left)
		current->items[index]->click();
	else
		current->items[index]->rclick();
}



/***********************************************************************
     * Menu
     * select

***********************************************************************/
void ach::Menu::select(int i)
{
	if (binding && (void*)current->items[i] != (void*)binding && i != (int)current->items.size() - 1)
		return;

	if (index != i)
	{
		index = i;
		sm->play(sfxBlip);
	}
}



/***********************************************************************
     * Menu
     * move

***********************************************************************/
void ach::Menu::move(int d)
{
	select(interval_loop(index + d, 0, current->items.size() - 1));
}
