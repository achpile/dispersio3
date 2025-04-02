#ifndef __PARTICLE_WIND
#define __PARTICLE_WIND


namespace ach
{
	struct ParticleSystemWind : ParticleSystem
	{
		ach::Direction dir;
		sf::FloatRect  rect;
		sf::Vector2f   vel;

		float age;
		float freq;

		float side;
		float start;
		float offset;


		 ParticleSystemWind(sf::FloatRect _rect, ach::Direction _dir, float speed);
		~ParticleSystemWind();

		bool update();
		bool process(ach::Particle *particle);

		void add(float x);
	};
}

#endif
