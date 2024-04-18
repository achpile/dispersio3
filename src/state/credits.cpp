#include "meta/headers.hpp"


/***********************************************************************
     * StateCredits
     * constructor

***********************************************************************/
ach::StateCredits::StateCredits()
{
	pos = RENDER_LAYER_GUI_Y;

	fill();

	app->mouse(false);
}



/***********************************************************************
     * StateCredits
     * destructor

***********************************************************************/
ach::StateCredits::~StateCredits()
{
	listDelete(lines);
}



/***********************************************************************
     * StateCredits
     * update

***********************************************************************/
void ach::StateCredits::update()
{
	float offset = tm->frame * CREDITS_SPEED;

	for (unsigned int i = 0; i < lines.size(); i++)
		lines[i]->move(0, -offset);

	if (lines.back()->getGlobalBounds().top < -lines.back()->getGlobalBounds().height)
		app->stateSet(ach::GameState::gsMenu);

	bg->stars->update();

	render();
}



/***********************************************************************
     * StateCredits
     * render

***********************************************************************/
void ach::StateCredits::render()
{
	for (unsigned int i = 0; i < lines.size(); i++)
		rm->draw(lines[i], ach::RenderLayer::rlGUI);
}



/***********************************************************************
     * StateCredits
     * event

***********************************************************************/
void ach::StateCredits::event(sf::Event e)
{
	if ((e.type == sf::Event::MouseButtonPressed) || (e.type == sf::Event::KeyPressed))
		app->stateSet(ach::GameState::gsMenu);
}



/***********************************************************************
     * StateCredits
     * fill

***********************************************************************/
void ach::StateCredits::fill()
{
	add(PROJECT_NAME " v" PROJECT_VERS, ach::CreditsWeight::cwTitle);

	add("Developer", ach::CreditsWeight::cwHeader);
	add("Achpile", ach::CreditsWeight::cwEntry);
	add("Achpile2", ach::CreditsWeight::cwEntry);

	space();

	add("Developer2", ach::CreditsWeight::cwHeader);
	add("Achpile", ach::CreditsWeight::cwEntry);
	add("Achpile2", ach::CreditsWeight::cwEntry);
}



/***********************************************************************
     * StateCredits
     * add

***********************************************************************/
void ach::StateCredits::add(sf::String string, ach::CreditsWeight weight)
{
	sf::Text *line = new sf::Text();

	line->setFont(*resources->fonts.credits);
	line->setString(string);
	line->setCharacterSize(getSize(weight));
	line->setPosition(text_align(line, CREDITS_LEFT, RENDER_LAYER_GUI_X - CREDITS_LEFT * 2, getAlign(weight)), pos);
	line->setStyle(getStyle(weight));
	line->setFillColor(sf::Color::White);

	pos += getOffset(weight);

	lines.push_back(line);
}



/***********************************************************************
     * StateCredits
     * space

***********************************************************************/
void ach::StateCredits::space()
{
	pos += getOffset(ach::CreditsWeight::cwEntry);
}



/***********************************************************************
     * StateCredits
     * getSize

***********************************************************************/
int ach::StateCredits::getSize(ach::CreditsWeight weight)
{
	switch (weight)
	{
		case ach::CreditsWeight::cwTitle : return 48;
		case ach::CreditsWeight::cwHeader: return 36;
		case ach::CreditsWeight::cwEntry : return 24;
	}

	return 0;
}



/***********************************************************************
     * StateCredits
     * getOffset

***********************************************************************/
float ach::StateCredits::getOffset(ach::CreditsWeight weight)
{
	switch (weight)
	{
		case ach::CreditsWeight::cwTitle : return 120.0f;
		case ach::CreditsWeight::cwHeader: return 60.0f;
		case ach::CreditsWeight::cwEntry : return 50.0f;
	}

	return 0.0f;
}



/***********************************************************************
     * StateCredits
     * getAlign

***********************************************************************/
ach::TextAlign ach::StateCredits::getAlign(ach::CreditsWeight weight)
{
	switch (weight)
	{
		case ach::CreditsWeight::cwTitle : return ach::TextAlign::taCenter;
		case ach::CreditsWeight::cwHeader: return ach::TextAlign::taCenter;
		case ach::CreditsWeight::cwEntry : return ach::TextAlign::taLeft;
	}

	return ach::TextAlign::taLeft;
}



/***********************************************************************
     * StateCredits
     * getStyle

***********************************************************************/
sf::Uint32 ach::StateCredits::getStyle(ach::CreditsWeight weight)
{
	switch (weight)
	{
		case ach::CreditsWeight::cwTitle : return sf::Text::Bold;
		case ach::CreditsWeight::cwHeader: return sf::Text::Regular;
		case ach::CreditsWeight::cwEntry : return sf::Text::Regular;
	}

	return ach::TextAlign::taLeft;
}
