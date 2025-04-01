#ifndef __FRAMEWORK_MATH_VECTOR
#define __FRAMEWORK_MATH_VECTOR


float         vector_dot(sf::Vector2f a, sf::Vector2f b);
float         vector_len(sf::Vector2f v);
float         vector_angle(sf::Vector2f v);

sf::Vector2f  vector_create(float a);
sf::Vector2f  vector_perpendicular(sf::Vector2f v);
sf::Vector2f  vector_alike(sf::Vector2f v, sf::Vector2f a);
sf::Vector2f  vector_mirror(sf::Vector2f v, sf::Vector2f n);
sf::Vector2f  vector_norm(sf::Vector2f v);
sf::Vector2f  vector_set_len(sf::Vector2f v, float l);
sf::Vector2f  vector_bisector(sf::Vector2f a, sf::Vector2f b);
sf::Vector2f  vector_mult(sf::Vector2f a, sf::Vector2f b);
sf::Vector2f  vector_mult(sf::Vector2i a, sf::Vector2i b);
sf::Vector2i  vector_mult_i(sf::Vector2i a, sf::Vector2i b);
sf::Vector2f  vector_placement(sf::FloatRect dest, sf::FloatRect rect);

sf::Vector2f  vector_json_coord (json_t *j, const char *x = "x", const char *y = "y");
sf::Vector2i  vector_json_tile  (json_t *j, const char *x = "X", const char *y = "Y");
sf::FloatRect vector_json_rect  (json_t *j);
sf::Vector2f  vector_json_center(json_t *j);

sf::Vector2f  vector_tile_coord (int x, int y, int size);
sf::Vector2f  vector_tile_center(int x, int y, int size);
sf::Vector2f  vector_tile_bottom(int x, int y, int size);

#endif
