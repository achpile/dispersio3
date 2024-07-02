#ifndef __MODEL_BASE
#define __MODEL_BASE


namespace ach
{
	struct Model
	{
		ach::DataModel *base;
		ach::Sheet     *sheet;
		ach::Animation  anim;

		sf::Vector2f    scale;
		sf::Color       color;

		char  animation[STR_LEN_NAME];


		 Model(ach::DataModel *_base);
		 Model(ach::DataSheet *_sheet);
		~Model();

		void update();
		void render(sf::Vector2f pos);

		void init(ach::Sheet *_sheet);

		void setColor(sf::Color _color);
		void setScale(float _scale);
		void setAnimation(const char *name);
	};
}

#endif
