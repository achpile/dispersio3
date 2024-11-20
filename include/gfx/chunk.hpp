#ifndef __GFX_CHUNK
#define __GFX_CHUNK


namespace ach
{
	struct EffectChunk : Effect
	{
		 EffectChunk();
		~EffectChunk();

		bool update();
		void render();
	};
}

#endif
