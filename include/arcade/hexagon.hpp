#ifndef __ARCADE_HEXAGON
#define __ARCADE_HEXAGON


namespace ach
{
	struct ArcadeHexagon : Arcade
	{
		ach::Framer         ticker;
		ach::Timer          rotor;

		sf::CircleShape    *center;
		sf::CircleShape    *player;
		sf::ConvexShape    *shape;

		sf::RenderTexture  *out;
		sf::Sprite         *screen;
		sf::Vertex          line[2];
		sf::Vector2f        cntr;

		float sectors[6];
		float speed;
		float rot;
		float pos;


		 ArcadeHexagon(bool select);
		~ArcadeHexagon();

		void prepare();
		void process();
		void draw();
		void handle();

		void fill();
		void rotate();
		void move(int d);
		bool check();
		bool collide(float angle);

		void renderLine(int i);
		void renderShape(int i, float dist);

		sf::Vector2f convert(int i      , float radius);
		sf::Vector2f convert(float angle, float radius);
	};
}

#endif
