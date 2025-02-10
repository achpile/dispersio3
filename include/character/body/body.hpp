#ifndef __CHARACTER_BODY_BODY
#define __CHARACTER_BODY_BODY


namespace ach
{
	struct Body
	{
		ach::Character *owner;
		ach::Model     *model;

		sf::Vector2f    barrel;


		         Body(ach::Character *_owner, ach::DataModel *_base);
		virtual ~Body();

		void update();
		void render();

		void setColor(sf::Color color);

		virtual void aim()     {};
		virtual void animate() {};
		virtual void flip()    {};
		virtual void reset()   {};

		static ach::Body *create(ach::Character *_owner, ach::DataModel *_base);
	};
}

#endif
