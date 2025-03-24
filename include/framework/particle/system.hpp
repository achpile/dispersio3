#ifndef __FRAMEWORK_PARTICLE_SYSTEM
#define __FRAMEWORK_PARTICLE_SYSTEM


namespace ach
{
	struct ParticleSystem
	{
		std::vector<ach::Particle*> particles;
		sf::RectangleShape         *spr;

		ach::RenderLayer            layer;

		bool realtime;


		         ParticleSystem(float size);
		         ParticleSystem(sf::Vector2f size);
		virtual ~ParticleSystem();

		virtual bool update();
		virtual bool process(ach::Particle *particle);

		void render();
	};
}

#endif
