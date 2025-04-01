#ifndef __MODEL_MODEL
#define __MODEL_MODEL


namespace ach
{
	struct Model
	{
		ach::DataModel   *base;
		ach::Sheet       *sheet;
		ach::Animation    anim;

		ach::RenderLayer  layer;

		sf::Vector2f      scale;
		sf::Color         color;

		char  animation[STR_LEN_NAME];
		float angle;


		 Model(ach::DataModel *_base);
		 Model(ach::DataSheet *_sheet);
		~Model();

		void update();
		void render(sf::Vector2f pos);

		void init(ach::DataSheet *_sheet);

		void setColor(sf::Color _color);
		void setScale(float _scale);
		void setScale(sf::Vector2f _size);
		void setAnimation(const char *name);
	};
}

#endif
