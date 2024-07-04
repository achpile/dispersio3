#ifndef __FRAMEWORK_COLLISION_ALGO
#define __FRAMEWORK_COLLISION_ALGO


bool collision_box_vs_line(sf::FloatRect box, ach::Line line, sf::Vector2f *c = NULL, sf::Vector2f *n = NULL);

#endif
