#include "meta/headers.hpp"
#include "meta/globals.hpp"


/***********************************************************************
     * Main function

***********************************************************************/
int main()
{
	app = new ach::App();
	srand(time(NULL));

	while(app->isRunning) app->update();
	delete app;

	return EXIT_SUCCESS;
}
