#ifndef __GFX_CHUNK
#define __GFX_CHUNK


namespace ach
{
	struct EffectChunk : Effect
	{
		 EffectChunk(sf::Vector2f pos, sf::Vector2f vel, sf::Color color);
		~EffectChunk();

		bool update();
		void render();
	};
}

#endif
