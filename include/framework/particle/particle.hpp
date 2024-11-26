#ifndef __FRAMEWORK_PARTICLE_PARTICLE
#define __FRAMEWORK_PARTICLE_PARTICLE


namespace ach
{
	struct Particle
	{
		sf::RectangleShape *spr;
		sf::Color           color;

		ach::Line    line;
		sf::Vector2f offset;
		sf::Vector2f pos;
		sf::Vector2f vel;
		sf::Vector2f acc;

		bool  moving;
		float age;
		float scale;


		 Particle();
		~Particle();

		void update(float frame);
		void render(ach::RenderLayer layer);

		void calc();
	};
}

#endif
