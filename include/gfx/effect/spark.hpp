#ifndef __GFX_EFFECT_SPARK
#define __GFX_EFFECT_SPARK


namespace ach
{
	struct EffectSpark : Effect
	{
		ach::ParticleSystemSplash *particle;


		 EffectSpark(sf::Vector2f pos, sf::Vector2f dir, sf::Color color);
		~EffectSpark();

		bool update();
		void render();
	};
}

#endif
