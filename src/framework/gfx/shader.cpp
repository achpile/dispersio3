#include "meta/headers.hpp"


/***********************************************************************
     * Shader
     * constructor

***********************************************************************/
ach::Shader::Shader(const char *code)
{
	if (!code)
	{
		states = sf::RenderStates::Default;
		return;
	}

	shader.loadFromMemory(code, sf::Shader::Fragment);

	states = sf::RenderStates(&shader);
}



/***********************************************************************
     * Shader
     * destructor

***********************************************************************/
ach::Shader::~Shader()
{
}
