#ifndef __FRAMEWORK_MATH_RECT
#define __FRAMEWORK_MATH_RECT


sf::Vector2f rect_pos   (sf::FloatRect r);
sf::Vector2f rect_size  (sf::FloatRect r);
sf::Vector2f rect_center(sf::FloatRect r);

sf::Vector2f rect_lt(sf::FloatRect r);
sf::Vector2f rect_rt(sf::FloatRect r);
sf::Vector2f rect_lb(sf::FloatRect r);
sf::Vector2f rect_rb(sf::FloatRect r);

ach::Line rect_line(sf::FloatRect r, ach::Direction d);

#endif
