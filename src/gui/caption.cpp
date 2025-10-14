#include "meta/headers.hpp"


/***********************************************************************
     * Caption
     * constructor

***********************************************************************/
ach::Caption::Caption(sf::String caption)
{
	fader.set(2.0f);

	spr = new sf::Sprite();
	tex = new sf::RenderTexture();

	sf::Text *text = new sf::Text(caption, *theme->credits->font, theme->credits->size * 2);

	text->setFillColor(sf::Color::White);
	text->setOutlineColor(sf::Color::Black);
	text->setOutlineThickness(3.0f);
	text->setPosition((RENDER_LAYER_GUI_X - text->getGlobalBounds().width) / 2.0f, GUI_MAP_CAPTION_Y);

	tex->create(RENDER_LAYER_GUI_X, RENDER_LAYER_GUI_Y);
	tex->setSmooth(false);
	tex->setRepeated(false);
	tex->setActive(true);
	tex->clear(sf::Color::Transparent);
	tex->draw(*text);
	tex->display();

	spr->setTexture(tex->getTexture());

	delete text;
}



/***********************************************************************
     * Caption
     * destructor

***********************************************************************/
ach::Caption::~Caption()
{
	delete spr;
	delete tex;
}



/***********************************************************************
     * Caption
     * update

***********************************************************************/
void ach::Caption::update()
{
	if (!fader.update())
		return;

	spr->setColor(sf::Color(255, 255, 255, 255 * ((fader.value > 1.0f) ? 1 : fader.value)));
}



/***********************************************************************
     * Caption
     * render

***********************************************************************/
void ach::Caption::render()
{
	if (!fader.active())
		return;

	rm->draw(spr, ach::RenderLayer::rlGUI);
}
