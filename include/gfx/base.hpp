#ifndef __GFX_BASE
#define __GFX_BASE


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
