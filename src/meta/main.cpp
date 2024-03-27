#include <random>
#include <ctime>

#include "meta/app.hpp"
#include "meta/global.hpp"


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
