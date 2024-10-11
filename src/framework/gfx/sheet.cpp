#include "meta/headers.hpp"


/***********************************************************************
     * Sheet
     * constructor

***********************************************************************/
ach::Sheet::Sheet(const char *filename, unsigned int _frames, ach::SheetOrigin origin)
{
	sf::IntRect rect;
	int         step;

	frames = _frames;

	tex = new sf::Texture();

	if (!tex->loadFromFile(filename))
	{
		logger->log(ach::LogLevel::llError, "Error loading texture: '%s'", filename);
		return;
	}

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
		spr[i]->setOrigin(getOrigin(origin));
	}
}



/***********************************************************************
     * Sheet
     * destructor

***********************************************************************/
ach::Sheet::~Sheet()
{
	list_delete(spr);

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



/***********************************************************************
     * Sheet
     * getOrigin

***********************************************************************/
sf::Vector2f ach::Sheet::getOrigin(ach::SheetOrigin origin)
{
	switch (origin)
	{
		case ach::SheetOrigin::soCenter: return sf::Vector2f(size.x / 2.0f, size.y / 2.0f);
		case ach::SheetOrigin::soBottom: return sf::Vector2f(size.x / 2.0f, size.y       );
		case ach::SheetOrigin::soNone  : return sf::Vector2f(0.0f         , 0.0f         );
		default                        : return sf::Vector2f(0.0f         , 0.0f         );
	}
}
