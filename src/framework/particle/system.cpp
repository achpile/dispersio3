#include "meta/headers.hpp"


/***********************************************************************
     * ParticleSystem
     * constructor

***********************************************************************/
ach::ParticleSystem::ParticleSystem(float size)
{
	spr = new sf::RectangleShape(sf::Vector2f(size, size));

	spr->setOrigin(size / 2.0f, size / 2.0f);
}



/***********************************************************************
     * ParticleSystem
     * constructor

***********************************************************************/
ach::ParticleSystem::ParticleSystem(sf::Vector2f size)
{
	spr = new sf::RectangleShape(size);

	spr->setOrigin(size.x / 2.0f, size.y / 2.0f);
}



/***********************************************************************
     * ParticleSystem
     * destructor

***********************************************************************/
ach::ParticleSystem::~ParticleSystem()
{
	delete spr;

	list_delete(particles);
}



/***********************************************************************
     * ParticleSystem
     * update

***********************************************************************/
bool ach::ParticleSystem::update()
{
	return false;
}



/***********************************************************************
     * ParticleSystem
     * process

***********************************************************************/
bool ach::ParticleSystem::process(ach::Particle*)
{
	return false;
}



/***********************************************************************
     * ParticleSystem
     * render

***********************************************************************/
void ach::ParticleSystem::render()
{
	unsigned int i = 0;

	while (i < particles.size())
	{
		particles[i]->update(tm->get(real));

		if (!process(particles[i]))
		{
			delete particles[i];
			particles.erase(particles.begin() + i);

			continue;
		}

		particles[i]->render(layer);
		i++;
	}
}
