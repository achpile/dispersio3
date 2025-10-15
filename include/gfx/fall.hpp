#ifndef __GFX_FALL
#define __GFX_FALL


namespace ach
{
	struct EffectFall : Effect
	{
		ach::Boss  *boss;
		ach::Model *model;
		ach::Phys   phys;

		float limit;


		 EffectFall(ach::Boss *_boss, ach::DataSheet *sheet, sf::Vector2f pos, float _limit);
		~EffectFall();

		bool update();
		void render();
	};
}

#endif
