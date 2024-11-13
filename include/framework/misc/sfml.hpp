#ifndef __FRAMEWORK_MISC_SFML
#define __FRAMEWORK_MISC_SFML


void sfml_load_font   (sf::Font        **font   , const char *filename);
void sfml_load_sound  (sf::SoundBuffer **sound  , const char *filename);
void sfml_load_image  (sf::Image       **image  , const char *filename);
void sfml_load_texture(sf::Texture     **texture, const char *filename);

#endif
