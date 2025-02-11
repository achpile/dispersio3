#ifndef __GFX_SPLASH
#define __GFX_SPLASH


namespace ach
{
	struct EffectSplash : Effect
	{
		ach::ParticleSystemSplash *particle;


		 EffectSplash(sf::Vector2f pos, sf::Color color);
		~EffectSplash();

		bool update();
		void render();
	};
}

#endif
