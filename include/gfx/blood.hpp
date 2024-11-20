#ifndef __GFX_BLOOD
#define __GFX_BLOOD


namespace ach
{
	struct EffectBlood : Effect
	{
		 EffectBlood(sf::Vector2f pos, sf::Vector2f vel, sf::Color color);
		~EffectBlood();

		bool update();
		void render();
	};
}

#endif
