#ifndef __CHARACTER_BODY_BODY
#define __CHARACTER_BODY_BODY


namespace ach
{
	struct Body
	{
		std::vector<ach::BodyPart*> parts;
		ach::Character             *owner;

		sf::Vector2f barrel;


		         Body(ach::Character *_owner, ach::DataBody *_base);
		virtual ~Body();

		void update();
		void render();

		void setColor(sf::Color color);

		virtual void aim()     {};
		virtual void animate() {};
		virtual void flip()    {};
		virtual void reset()   {};

		static ach::Body *create(ach::Character *_owner, ach::DataBody *_base);
	};
}

#endif
