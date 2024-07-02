#ifndef __PARTICLE_SMOKE
#define __PARTICLE_SMOKE


namespace ach
{
	struct ParticleSystemSmoke : ParticleSystem
	{
		sf::Vector2f pos;
		sf::Color    color;


		float age;
		float freq;
		float life;


		 ParticleSystemSmoke();
		~ParticleSystemSmoke();

		bool update();
		bool process(ach::Particle *particle);

		void add();
	};
}

#endif
