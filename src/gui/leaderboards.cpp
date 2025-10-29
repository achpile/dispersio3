#include "meta/headers.hpp"


/***********************************************************************
     * Leaderboards
     * constructor

***********************************************************************/
ach::Leaderboards::Leaderboards()
{
	active  = false;
	padding = MENU_PADDING;
	width   = RENDER_LAYER_GUI_X - MENU_LEADER_WIDTH - padding * 3;

	boxSelect = new ach::RectangleShape();
	boxClass  = new ach::RectangleShape();
	boxList   = new ach::RectangleShape();
	boxBack   = new ach::RectangleShape();

	boxSelect->setOutlineThickness(MENU_THICKNESS);
	boxClass->setOutlineThickness(MENU_THICKNESS);
	boxList->setOutlineThickness(MENU_THICKNESS);
	boxBack->setOutlineThickness(MENU_THICKNESS);

	style();
	translate();
}



/***********************************************************************
     * Leaderboards
     * destructor

***********************************************************************/
ach::Leaderboards::~Leaderboards()
{
	delete boxSelect;
	delete boxClass;
	delete boxList;
	delete boxBack;
}



/***********************************************************************
     * Leaderboards
     * update

***********************************************************************/
void ach::Leaderboards::update()
{
}



/***********************************************************************
     * Leaderboards
     * render

***********************************************************************/
void ach::Leaderboards::render()
{
	rm->draw(boxSelect, ach::RenderLayer::rlGUI);
	rm->draw(boxClass , ach::RenderLayer::rlGUI);
	rm->draw(boxList  , ach::RenderLayer::rlGUI);
	rm->draw(boxBack  , ach::RenderLayer::rlGUI);
}



/***********************************************************************
     * Leaderboards
     * event

***********************************************************************/
void ach::Leaderboards::event(sf::Event)
{
}



/***********************************************************************
     * Leaderboards
     * translate

***********************************************************************/
void ach::Leaderboards::translate()
{
}



/***********************************************************************
     * Leaderboards
     * style

***********************************************************************/
void ach::Leaderboards::style()
{
	spacing = theme->menu.text->spacing() + MENU_SPACING;

	pos.x   = padding;
	pos.y   = RENDER_LAYER_GUI_Y - padding * 3 - spacing * 15;

	boxSelect->setPosition(pos);
	boxClass->setPosition (sf::Vector2f(pos.x + MENU_LEADER_WIDTH + padding, pos.y               ));
	boxList->setPosition  (sf::Vector2f(pos.x + MENU_LEADER_WIDTH + padding, pos.y + spacing * 3 ));
	boxBack->setPosition  (sf::Vector2f(pos.x + MENU_LEADER_WIDTH + padding, pos.y + spacing * 14));

	boxSelect->setSize(sf::Vector2f(MENU_LEADER_WIDTH, padding * 2 + spacing * 15));
	boxClass->setSize (sf::Vector2f(width            , padding * 2 + spacing * 1));
	boxList->setSize  (sf::Vector2f(width            , padding * 2 + spacing * 9));
	boxBack->setSize  (sf::Vector2f(width            , padding * 2 + spacing * 1));

	boxSelect->style(theme->menu.box);
	boxClass->style(theme->menu.box);
	boxList->style(theme->menu.box);
	boxBack->style(theme->menu.box);
}



/***********************************************************************
     * Leaderboards
     * controls

***********************************************************************/
void ach::Leaderboards::controls()
{
}



/***********************************************************************
     * Leaderboards
     * init

***********************************************************************/
void ach::Leaderboards::init(bool)
{
	data.clear();

	active = true;
}
