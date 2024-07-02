#ifndef __PARTICLE_STARS
#define __PARTICLE_STARS


namespace ach
{
	struct ParticleSystemStars : ParticleSystem
	{
		float age;
		float freq;


		 ParticleSystemStars();
		~ParticleSystemStars();

		bool update();
		bool process(ach::Particle *particle);

		void add(float x);
	};
}

#endif
