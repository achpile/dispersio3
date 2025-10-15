#ifndef __GFX_BREAK
#define __GFX_BREAK


namespace ach
{
	struct EffectBreak : Effect
	{
		ach::ParticleSystemSplash *particle;


		 EffectBreak(sf::Vector2f pos, sf::Sprite *spr, float life, float speed);
		~EffectBreak();

		bool update();
		void render();
	};
}

#endif
