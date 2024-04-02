#ifndef __FRAMEWORK_MATH_VECTOR
#define __FRAMEWORK_MATH_VECTOR


float        vector_dot(sf::Vector2f a, sf::Vector2f b);
float        vector_len(sf::Vector2f v);
sf::Vector2f vector_norm(sf::Vector2f v);
sf::Vector2f vector_set_len(sf::Vector2f v, float l);

#endif
