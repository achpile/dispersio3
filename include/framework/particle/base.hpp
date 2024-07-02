#ifndef __FRAMEWORK_PARTICLE_BASE
#define __FRAMEWORK_PARTICLE_BASE


namespace ach
{
	struct Particle
	{
		sf::RectangleShape *spr;
		sf::Color           color;

		sf::Vector2f offset;
		sf::Vector2f pos;
		sf::Vector2f vel;
		sf::Vector2f acc;

		float age;
		float scale;


		 Particle();
		~Particle();

		void update(float frame);
		void render(ach::RenderLayer layer);
	};
}

#endif
