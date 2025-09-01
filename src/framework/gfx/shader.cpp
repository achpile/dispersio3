#include "meta/headers.hpp"


/***********************************************************************
     * shader_init

***********************************************************************/
void shader_init()
{
	shaders.white.loadFromMemory(GFX_SHADER_WHITE , sf::Shader::Fragment);
	shaders.grey.loadFromMemory (GFX_SHADER_GREY  , sf::Shader::Fragment);

	states.white  = sf::RenderStates(&shaders.white);
	states.grey   = sf::RenderStates(&shaders.grey );
}
