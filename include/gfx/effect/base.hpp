#ifndef __GFX_EFFECT_BASE
#define __GFX_EFFECT_BASE


namespace ach
{
	struct Effect
	{
		         Effect();
		virtual ~Effect();

		virtual bool update();
		virtual void render() {};
	};
}

#endif
