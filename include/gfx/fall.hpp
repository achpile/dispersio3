#ifndef __GFX_FALL
#define __GFX_FALL


namespace ach
{
	struct EffectFall : Effect
	{
		ach::Phys phys;

		float limit;


		 EffectFall(sf::Vector2f pos, float _limit);
		~EffectFall();

		bool update();
		void render();
	};
}

#endif
