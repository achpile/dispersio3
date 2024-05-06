#ifndef __CHARACTER_BASE
#define __CHARACTER_BASE


namespace ach
{
	struct Character
	{
		std::vector<ach::Model*> models;

		ach::Phys    phys;
		sf::Vector2f aim;


		 Character(sf::Vector2f size);
		~Character();

		void update();
		void render();

		void reset();
	};
}

#endif
