#ifndef __GFX_BLOOD
#define __GFX_BLOOD


namespace ach
{
	struct EffectBlood : Effect
	{
		ach::ProcessWorld         *world;
		ach::ParticleSystemSplash *particle;

		sf::Color color;


		 EffectBlood(ach::ProcessWorld *_world, sf::Vector2f pos, sf::Vector2f vel, sf::Color _color);
		~EffectBlood();

		bool update();
		void render();
	};
}

#endif
