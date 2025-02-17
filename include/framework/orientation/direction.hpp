#ifndef __FRAMEWORK_ORIENTATION_DIRECTION
#define __FRAMEWORK_ORIENTATION_DIRECTION


namespace ach
{
	enum Direction
	{
		dDown = 0,
		dLeft,
		dRight,
		dUp,
		dCount
	};
}



sf::Vector2i   dir_vector(ach::Direction d);
ach::Direction dir_invert(ach::Direction d);

#endif
