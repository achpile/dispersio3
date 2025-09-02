#ifndef __FRAMEWORK_GFX_SHADER
#define __FRAMEWORK_GFX_SHADER


namespace ach
{
	struct Shader
	{
		sf::RenderStates states;
		sf::Shader       shader;


		 Shader(const char *code);
		~Shader();
	};
}

#endif
