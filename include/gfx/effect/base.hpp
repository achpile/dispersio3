#ifndef __GFX_EFFECT_BASE
#define __GFX_EFFECT_BASE


namespace ach
{
	enum EffectType
	{
		etNone = 0
	};


	struct Effect
	{
		         Effect();
		virtual ~Effect();

		virtual bool update();
		virtual void render() {};
	};
}

#endif
