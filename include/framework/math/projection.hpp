#ifndef __FRAMEWORK_MATH_PROJECTION
#define __FRAMEWORK_MATH_PROJECTION


float projection_vector(sf::Vector2f a, bool vertical);
float projection_rect_pos(sf::FloatRect rect, bool vertical);
float projection_rect_len(sf::FloatRect rect, bool vertical);
float projection_rect_tip(sf::FloatRect rect, bool vertical);

#endif
