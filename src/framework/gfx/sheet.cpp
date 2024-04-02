#include "meta/headers.hpp"


/***********************************************************************
     * Sheet
     * constructor

***********************************************************************/
ach::Sheet::Sheet(const char *filename, unsigned int _frames, bool centered)
{
	sf::IntRect rect;
	int         step;

	frames = _frames;

	tex = new sf::Texture();

	tex->loadFromFile(filename);
	tex->setSmooth(false);

	step = tex->getSize().x / frames;
	size = sf::Vector2f(step, tex->getSize().y);
	rect = sf::IntRect(0, 0, step, tex->getSize().y);


	for (unsigned int i = 0; i < frames; i++)
	{
		rect.left = i * step;

		spr.push_back(new sf::Sprite());
		spr[i]->setTexture(*tex);
		spr[i]->setTextureRect(rect);

		if (centered)
			spr[i]->setOrigin(step / 2.0f, size.y / 2.0f);
	}
}



/***********************************************************************
     * Sheet
     * destructor

***********************************************************************/
ach::Sheet::~Sheet()
{
	listDelete(spr);

	delete tex;
}



/***********************************************************************
     * Sheet
     * getFrame

***********************************************************************/
sf::Sprite* ach::Sheet::getFrame(unsigned int frame)
{
	return spr[frame % spr.size()];
}
