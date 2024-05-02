#ifndef __GFX_MODEL
#define __GFX_MODEL


namespace ach
{
	struct Model
	{
		ach::DataModel *base;
		ach::Animation  anim;

		sf::Color       color;

		char  animation[STR_LEN_NAME];
		float scale;


		 Model(ach::DataModel *_base);
		~Model();

		void update();
		void render(sf::Vector2f pos);

		void setAnimation(const char *name);
	};
}

#endif
