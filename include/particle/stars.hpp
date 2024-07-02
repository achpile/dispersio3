#ifndef __PARTICLE_STARS
#define __PARTICLE_STARS


namespace ach
{
	struct ParticleSystemStars : ParticleSystem
	{
		float age;
		float freq;

		int   width;
		int   height;


		 ParticleSystemStars(int _width, int _height, int count);
		~ParticleSystemStars();

		bool update();
		bool process(ach::Particle *particle);

		void add(float x);
	};
}

#endif
