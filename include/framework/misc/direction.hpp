#ifndef __FRAMEWORK_MISC_DIRECTION
#define __FRAMEWORK_MISC_DIRECTION


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



sf::Vector2i   dir_vector(ach::Direction dir);
ach::Direction dir_invert(ach::Direction dir);

#endif
