#ifndef __GFX_SHEET
#define __GFX_SHEET


namespace ach
{
	struct EffectSheet : Effect
	{
		ach::Model   *model;

		sf::Vector2f  pos;


		 EffectSheet(ach::DataSheet *sheet, sf::Vector2f _pos, float size);
		~EffectSheet();

		bool update();
		void render();
	};
}

#endif
