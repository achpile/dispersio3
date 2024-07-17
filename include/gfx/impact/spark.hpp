#ifndef __GFX_IMPACT_SPARK
#define __GFX_IMPACT_SPARK


namespace ach
{
	struct ImpactSpark : Impact
	{
		ach::ParticleSystemSplash *particle;


		 ImpactSpark(sf::Vector2f _pos, sf::Vector2f _dir, sf::Color _color);
		~ImpactSpark();

		bool update();
		void render();
	};
}

#endif
