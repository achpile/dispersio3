#ifndef __GFX_GFX
#define __GFX_GFX


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
