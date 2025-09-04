#ifndef __FRAMEWORK_GFX_SLIDESHOW
#define __FRAMEWORK_GFX_SLIDESHOW


namespace ach
{
	struct SlideShow
	{
		std::vector<ach::Sprite*> *list;

		ach::Timer   timer;
		sf::Vector2f pos;

		unsigned int index;

		bool active;
		bool realtime;


		 SlideShow(std::vector<ach::Sprite*> *_list, bool _realtime);
		~SlideShow();

		void update();
		void render();

		void next();

		void setPosition(sf::Vector2f _pos);
		void setDuration(float duration);
	};
}

#endif
