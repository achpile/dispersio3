#include "meta/headers.hpp"


/***********************************************************************
     * Sprite
     * constructor

***********************************************************************/
ach::Sprite::Sprite(const char *filename, bool repeated, bool centered)
{
	tex = new sf::Texture();

	tex->loadFromFile(filename);
	tex->setSmooth(false);
	tex->setRepeated(repeated);

	spr = new sf::Sprite();
	spr->setTexture(*tex);

	size = sf::Vector2f(tex->getSize());

	if (centered)
		spr->setOrigin(size / 2.0f);
}



/***********************************************************************
     * Sprite
     * destructor

***********************************************************************/
ach::Sprite::~Sprite()
{
	delete spr;
	delete tex;
}
