#ifndef __FRAMEWORK_PARTICLE_SYSTEM
#define __FRAMEWORK_PARTICLE_SYSTEM


namespace ach
{
	struct ParticleSystem
	{
		std::vector<ach::Particle*> particles;
		sf::RectangleShape         *spr;


		         ParticleSystem(float size);
		virtual ~ParticleSystem();

		virtual bool update();
		virtual bool check(ach::Particle *particle);

		void render(ach::RenderLayer layer, float frame);
	};
}

#endif
