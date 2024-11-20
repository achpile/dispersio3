#ifndef __GFX_BLOOD
#define __GFX_BLOOD


namespace ach
{
	struct EffectBlood : Effect
	{
		 EffectBlood();
		~EffectBlood();

		bool update();
		void render();
	};
}

#endif
