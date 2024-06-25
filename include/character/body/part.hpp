#ifndef __CHARACTER_BODY_PART
#define __CHARACTER_BODY_PART


namespace ach
{
	struct BodyPart
	{
		ach::Model   *model;
		sf::Vector2f  offset;
		sf::Vector2i  flip;


		 BodyPart(json_t *obj);
		~BodyPart();

		bool update();
		void render(sf::Vector2f pos);

		void setAnimation(const char *name);
	};
}

#endif
