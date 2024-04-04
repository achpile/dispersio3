#include "meta/headers.hpp"


/***********************************************************************
     * Sprite
     * constructor

***********************************************************************/
ach::Sprite::Sprite(const char *filename, bool repeated, bool centered)
{
	tex = new sf::Texture();
	spr = new sf::Sprite();

	if (!tex->loadFromFile(filename))
	{
		logger->log(ach::LogLevel::llError, "Error loading texture: \"%s\"", filename);
		return;
	}

	tex->setSmooth(false);
	tex->setRepeated(repeated);

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
