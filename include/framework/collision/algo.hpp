#ifndef __FRAMEWORK_COLLISION_ALGO
#define __FRAMEWORK_COLLISION_ALGO


bool collision_box_vs_box(sf::FloatRect box, sf::FloatRect rect, sf::Vector2f *c = NULL, sf::Vector2f *n = NULL);
bool collision_box_vs_circle(sf::FloatRect box, sf::Vector2f center, float r, sf::Vector2f *c = NULL, sf::Vector2f *n = NULL);
bool collision_box_vs_line(sf::FloatRect box, ach::Line solid, sf::Vector2f *c = NULL, sf::Vector2f *n = NULL);
bool collision_line_vs_line(ach::Line line, ach::Line solid, sf::Vector2f *c = NULL, sf::Vector2f *n = NULL);

#endif
