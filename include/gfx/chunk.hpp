#ifndef __GFX_CHUNK
#define __GFX_CHUNK


namespace ach
{
	struct EffectChunk : Effect
	{
		ach::ProcessWorld *world;

		sf::Color color;


		 EffectChunk(ach::ProcessWorld *_world, sf::Vector2f pos, sf::Vector2f vel, sf::Color _color);
		~EffectChunk();

		bool update();
		void render();
	};
}

#endif
