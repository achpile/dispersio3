#ifndef __FRAMEWORK_GFX_SHADER
#define __FRAMEWORK_GFX_SHADER


struct {
	sf::Shader white;
	sf::Shader grey;
} shaders;


struct {
	sf::RenderStates white;
	sf::RenderStates grey;
} states;


void shader_init();

#endif
