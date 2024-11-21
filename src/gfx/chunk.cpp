#include "meta/headers.hpp"


/***********************************************************************
     * EffectChunk
     * constructor

***********************************************************************/
ach::EffectChunk::EffectChunk(ach::ProcessWorld *_world, sf::Vector2f , sf::Vector2f , sf::Color _color)
{
	world = _world;
	color = _color;
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
	return false;
}



/***********************************************************************
     * EffectChunk
     * render

***********************************************************************/
void ach::EffectChunk::render()
{
}
