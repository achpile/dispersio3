#ifndef __GFX_EXPLOSION
#define __GFX_EXPLOSION


namespace ach
{
	struct EffectExplosion : Effect
	{
		ach::Model   *model;

		sf::Vector2f  pos;


		 EffectExplosion(ach::DataSheet *sheet, sf::Vector2f _pos, float radius);
		~EffectExplosion();

		bool update();
		void render();
	};
}

#endif
