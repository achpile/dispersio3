#include "meta/headers.hpp"


/***********************************************************************
     * Particle
     * constructor

***********************************************************************/
ach::Particle::Particle()
{
	age    = 0.0f;
	scale  = 1.0f;
	moving = true;
	color  = sf::Color::White;
	pos    = sf::Vector2f(0.0f, 0.0f);
	vel    = sf::Vector2f(0.0f, 0.0f);
	acc    = sf::Vector2f(0.0f, 0.0f);
	offset = sf::Vector2f(0.0f, 0.0f);
}



/***********************************************************************
     * Particle
     * destructor

***********************************************************************/
ach::Particle::~Particle()
{
}



/***********************************************************************
     * Particle
     * update

***********************************************************************/
void ach::Particle::update(float frame)
{
	age += frame;

	if (moving)
	{
		vel += acc * frame;
		pos += vel * frame;

		line.b = line.a;
		line.a = pos;
		line.calc();
	}
}



/***********************************************************************
     * Particle
     * render

***********************************************************************/
void ach::Particle::render(ach::RenderLayer layer)
{
	spr->setPosition(pos + offset);
	spr->setFillColor(color);
	spr->setScale(scale, scale);

	rm->draw(spr, layer);
}



/***********************************************************************
     * Particle
     * calc

***********************************************************************/
void ach::Particle::calc()
{
	line.a = pos;
	line.b = pos;

	line.calc();
}
