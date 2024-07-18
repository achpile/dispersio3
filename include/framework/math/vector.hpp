#ifndef __FRAMEWORK_MATH_VECTOR
#define __FRAMEWORK_MATH_VECTOR


float         vector_dot(sf::Vector2f a, sf::Vector2f b);
float         vector_len(sf::Vector2f v);
float         vector_angle(sf::Vector2f v);

sf::Vector2f  vector_create(float a);
sf::Vector2f  vector_perpendicular(sf::Vector2f v);
sf::Vector2f  vector_alike(sf::Vector2f v, sf::Vector2f a);
sf::Vector2f  vector_mirror(sf::Vector2f v, sf::Vector2f n);
sf::Vector2f  vector_center(sf::FloatRect r);
sf::Vector2f  vector_norm(sf::Vector2f v);
sf::Vector2f  vector_set_len(sf::Vector2f v, float l);
sf::Vector2f  vector_mult(sf::Vector2f a, sf::Vector2f b);
sf::Vector2f  vector_mult(sf::Vector2i a, sf::Vector2i b);
sf::Vector2i  vector_mult_i(sf::Vector2i a, sf::Vector2i b);

sf::Vector2f  vector_json_coord(json_t *j, const char *x = "x", const char *y = "y");
sf::FloatRect vector_json_rect (json_t *j);

#endif
