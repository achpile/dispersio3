#ifndef __CHARACTER_BODY_BASE
#define __CHARACTER_BODY_BASE


namespace ach
{
	struct Body
	{
		std::vector<ach::BodyPart*> parts;
		ach::Character             *owner;


		         Body(ach::Character *_owner, ach::DataBody *_base);
		virtual ~Body();

		void update();
		void render();

		void setColor(sf::Color color);

		virtual void animate() {};
		virtual void reset()   {};

		static ach::Body *create(ach::Character *_owner, ach::DataBody *_base);
	};
}

#endif
