#ifndef __PARTICLE_SPLASH
#define __PARTICLE_SPLASH


namespace ach
{
	struct ParticleSystemSplash : ParticleSystem
	{
		sf::Vector2f pos;
		sf::Vector2f dir;
		sf::Color    color;

		float age;
		float life;
		float cone;
		float speed;

		bool  gravity;


		 ParticleSystemSplash(float size);
		~ParticleSystemSplash();

		bool update();
		bool process(ach::Particle *particle);

		void add(float angle);

		void init(int count);
	};
}


#endif
