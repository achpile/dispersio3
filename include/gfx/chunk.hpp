#ifndef __GFX_CHUNK
#define __GFX_CHUNK


namespace ach
{
	struct EffectChunk : Effect
	{
		ach::ProcessWorld *world;
		ach::Phys          phys;

		sf::Sprite *spr;
		sf::Color   color;

		float       age;
		float       angle;


		 EffectChunk(ach::ProcessWorld *_world, sf::Vector2f pos, sf::Vector2f vel, sf::Color _color, sf::Sprite *_spr);
		~EffectChunk();

		bool update();
		void render();
	};
}

#endif
