#ifndef __FRAMEWORK_PARTICLE_PARTICLE
#define __FRAMEWORK_PARTICLE_PARTICLE


namespace ach
{
	struct Particle
	{
		sf::RectangleShape *spr;
		sf::IntRect         rect;
		sf::Color           color;

		ach::Line    line;
		sf::Vector2f offset;
		sf::Vector2f pos;
		sf::Vector2f vel;
		sf::Vector2f acc;

		bool         moving;
		bool         rotate;
		float        age;
		float        scale;
		float        angle;


		 Particle();
		~Particle();

		void update(float frame);
		void render(ach::RenderLayer layer);

		void calc();
	};
}

#endif
