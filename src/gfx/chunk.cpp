#include "meta/headers.hpp"


/***********************************************************************
     * EffectChunk
     * constructor

***********************************************************************/
ach::EffectChunk::EffectChunk(ach::ProcessWorld *_world, sf::Vector2f pos, sf::Vector2f vel, sf::Color _color, sf::Sprite *_spr)
{
	world = _world;
	color = _color;
	spr   = _spr;
	age   = 0.0f;
	angle = 0.0f;

	phys.init(sf::Vector2f(PARTICLE_CHUNK_SIZE, PARTICLE_CHUNK_SIZE));
	phys.reset();

	phys.pos = pos;
	phys.vel = vector_set_len(vel, PARTICLE_CHUNK_SPEED);
	phys.acc = sf::Vector2f(0.0f, PHYS_GRAVITY / 2.0f);

	phys.calc();
}



/***********************************************************************
     * EffectChunk
     * destructor

***********************************************************************/
ach::EffectChunk::~EffectChunk()
{
}



/***********************************************************************
     * EffectChunk
     * update

***********************************************************************/
bool ach::EffectChunk::update()
{
	age   += tm->get(ach::TimeSource::tsFrame);
	angle += phys.vel.x * 16.0f * tm->get(ach::TimeSource::tsFrame);

	if (age > PARTICLE_CHUNK_LIFE)
		return false;

	world->map->collidePhysSteps(&phys);

	if (phys.grounded)
		phys.vel.x *= PARTICLE_CHUNK_SLOW;

	if (fabs(phys.vel.x) < PHYS_VEL_EPSILON)
		phys.vel.x = 0.0f;

	return true;
}



/***********************************************************************
     * EffectChunk
     * render

***********************************************************************/
void ach::EffectChunk::render()
{
	spr->setColor(sf::Color(color.r, color.g, color.b, color.a * math_decay(age, PARTICLE_CHUNK_CLEAR, PARTICLE_CHUNK_LIFE)));
	spr->setPosition(phys.pos);
	spr->setRotation(angle);

	rm->draw(spr, ach::RenderLayer::rlGame);
}
