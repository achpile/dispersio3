#ifndef __CHARACTER_BODY_PART
#define __CHARACTER_BODY_PART


namespace ach
{
	struct BodyPart
	{
		ach::Model   *model;
		sf::Vector2f  offset;


		 BodyPart(json_t *obj);
		~BodyPart();
	};
}

#endif
