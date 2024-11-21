#ifndef __GFX_BLOOD
#define __GFX_BLOOD


namespace ach
{
	struct EffectBlood : Effect
	{
		ach::ParticleSystemSplash *particle;

		sf::Color color;


		 EffectBlood(sf::Vector2f pos, sf::Vector2f vel, sf::Color _color);
		~EffectBlood();

		bool update();
		void render();
	};
}

#endif
