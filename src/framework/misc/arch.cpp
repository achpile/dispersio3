#include "meta/headers.hpp"


/***********************************************************************
     * arch_mkdir

***********************************************************************/
void arch_mkdir(const char *name)
{
#ifdef _WIN32
	mkdir(name);
#else
	mkdir(name, 0755);
#endif
}
