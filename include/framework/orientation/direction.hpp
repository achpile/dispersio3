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


ach::Direction   operator! (ach::Direction d);
ach::Orientation dir_orient(ach::Direction d);

sf::Vector2i   dir_vector_i(ach::Direction d);
sf::Vector2f   dir_vector_f(ach::Direction d);
int            dir_sign    (ach::Direction d);

#endif
