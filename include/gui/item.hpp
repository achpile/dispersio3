#ifndef __GUI_ITEM
#define __GUI_ITEM


namespace ach
{
	struct ItemIcon
	{
		ach::DataItem *base;
		ach::Model    *model;

		sf::Vector2f   pos;


		 ItemIcon(ach::DataItem *_base, sf::Vector2f _pos);
		~ItemIcon();

		bool update();
		void render();
	};
}

#endif
