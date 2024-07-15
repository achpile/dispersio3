#ifndef __GFX_TRACER_SMOKE
#define __GFX_TRACER_SMOKE


namespace ach
{
	struct TracerSmoke : Tracer
	{
		ach::ParticleSystemSmoke *smoke;


		 TracerSmoke(ach::Phys *_phys);
		~TracerSmoke();

		void update();
		void render();

		void init();
		void correct();
	};
}

#endif
