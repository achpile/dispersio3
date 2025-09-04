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
	mm->play(json_object_get_branch_string(dm->data, "Meta.Track.Credits"));
}



/***********************************************************************
     * StateCredits
     * destructor

***********************************************************************/
ach::StateCredits::~StateCredits()
{
	list_delete(lines);
}



/***********************************************************************
     * StateCredits
     * update

***********************************************************************/
void ach::StateCredits::update()
{
	float offset = tm->get(true) * TEXT_FLOW_CREDITS;

	list_foreach(lines)
		lines[i]->move(0, -offset);

	if (lines.back()->getGlobalBounds().top < -lines.back()->getGlobalBounds().height)
		app->stateSet(ach::GameState::gsMenu);

	stars->update();

	render();
}



/***********************************************************************
     * StateCredits
     * render

***********************************************************************/
void ach::StateCredits::render()
{
	stars->render();

	list_foreach(lines)
		rm->draw(lines[i], ach::RenderLayer::rlGUI);
}



/***********************************************************************
     * StateCredits
     * event

***********************************************************************/
void ach::StateCredits::event(sf::Event e)
{
	switch (e.type)
	{
		case sf::Event::MouseButtonReleased:
		case sf::Event::KeyPressed:
		case sf::Event::JoystickButtonPressed:
			app->stateSet(ach::GameState::gsMenu);

		default:
			break;
	}
}



/***********************************************************************
     * StateCredits
     * fill

***********************************************************************/
void ach::StateCredits::fill()
{
	add(PROJECT_NAME " v" PROJECT_VERS, ach::CreditsWeight::cwTitle);

	space();


	add(lm->get("UI.Credits.Developer"), ach::CreditsWeight::cwHeader);

	add("Achpile"                 , ach::CreditsWeight::cwEntry);
	add("http://achpile.github.io", ach::CreditsWeight::cwEntry);
	add("achpile@gmail.com"       , ach::CreditsWeight::cwEntry);
	space();


	add(lm->get("UI.Credits.Music"), ach::CreditsWeight::cwHeader);

	add("Creepue"                       , ach::CreditsWeight::cwEntry);
	add("https://vk.com/creepue_music"  , ach::CreditsWeight::cwEntry);
	add("https://youtube.com/c/creepue" , ach::CreditsWeight::cwEntry);
	add("https://soundcloud.com/creepue", ach::CreditsWeight::cwEntry);
	space();


	add(lm->get("UI.Credits.Sound"), ach::CreditsWeight::cwHeader);

	add("ChipTone by SFBGames"             , ach::CreditsWeight::cwEntry);
	add("https://sfbgames.itch.io/chiptone", ach::CreditsWeight::cwEntry);
	space();


	add(lm->get("UI.Credits.Lib"), ach::CreditsWeight::cwHeader);

	add("SFML"                , ach::CreditsWeight::cwEntry);
	add("http://sfml-dev.org/", ach::CreditsWeight::cwEntry);
	space();


	add(lm->get("UI.Credits.MapEditor"), ach::CreditsWeight::cwHeader);

	add("Tiled"                , ach::CreditsWeight::cwEntry);
	add("http://mapeditor.org/", ach::CreditsWeight::cwEntry);
	space();


	add(lm->get("UI.Credits.PrimaryTesting"), ach::CreditsWeight::cwHeader);
	add("Grisha92"      , ach::CreditsWeight::cwEntry);
	add("T1tan"         , ach::CreditsWeight::cwEntry);
	add("Smokey"        , ach::CreditsWeight::cwEntry);
	add("Mishgan-Zhigan", ach::CreditsWeight::cwEntry);
	space();


	add(lm->get("UI.Credits.Translations"), ach::CreditsWeight::cwHeader);

	translations();
	space();


	add(lm->get("UI.Credits.Special"), ach::CreditsWeight::cwHeader);

	add("garett90", ach::CreditsWeight::cwEntry);
}



/***********************************************************************
     * StateCredits
     * translations

***********************************************************************/
void ach::StateCredits::translations()
{
	sf::String  line;
	const char *key;
	size_t      i;

	json_t *author;
	json_t *item;

	json_object_foreach(json_object_get(dm->data, "Translation"), key, item)
	{
		line  = str_utf8(json_object_get_string(item, "Label"));
		line += " - ";

		json_array_foreach(json_object_get(item, "Author"), i, author)
		{
			if (i != 0)
				line += ", ";

			line += str_utf8(json_string_value(author));
		}

		add(line, ach::CreditsWeight::cwEntry);
	}
}



/***********************************************************************
     * StateCredits
     * add

***********************************************************************/
void ach::StateCredits::add(sf::String string, ach::CreditsWeight weight)
{
	sf::Text *line = new sf::Text();

	line->setFont(*theme->credits->font);
	line->setString(string);
	line->setCharacterSize(getSize(weight));
	line->setPosition(text_align(line, TEXT_FLOW_LEFT, RENDER_LAYER_GUI_X - TEXT_FLOW_LEFT * 2, getAlign(weight)), pos);
	line->setStyle(getStyle(weight));
	line->setFillColor(theme->credits->color);

	pos += getOffset(weight);

	lines.push_back(line);
}



/***********************************************************************
     * StateCredits
     * space

***********************************************************************/
void ach::StateCredits::space()
{
	pos += 100.0f;
}



/***********************************************************************
     * StateCredits
     * getSize

***********************************************************************/
int ach::StateCredits::getSize(ach::CreditsWeight weight)
{
	switch (weight)
	{
		case ach::CreditsWeight::cwTitle : return theme->credits->size * 2;
		case ach::CreditsWeight::cwHeader: return theme->credits->size * 1.5;
		case ach::CreditsWeight::cwEntry : return theme->credits->size;
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
