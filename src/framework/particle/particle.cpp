#include "meta/headers.hpp"


/***********************************************************************
     * Particle
     * constructor

***********************************************************************/
ach::Particle::Particle()
{
	age    = 0.0f;
	scale  = 1.0f;
	angle  = 0.0f;
	moving = true;
	rotate = false;
	color  = sf::Color::White;
	rect   = sf::IntRect (0, 0, 0, 0);
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

	if (rotate)
	{
		angle += vel.x * frame * 4.0f;
	}
}



/***********************************************************************
     * Particle
     * render

***********************************************************************/
void ach::Particle::render(ach::RenderLayer layer)
{
	spr->setPosition(pos + offset);
	spr->setTextureRect(rect);
	spr->setFillColor(color);
	spr->setScale(scale, scale);
	spr->setRotation(angle);

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
