#ifndef __PARTICLE_STARS
#define __PARTICLE_STARS


namespace ach
{
	struct Stars : ParticleSystem
	{
		float age;
		float freq;


		 Stars();
		~Stars();

		bool update();
		bool check(ach::Particle *particle);

		void add(float x);
	};
}

#endif
