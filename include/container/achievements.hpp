#ifndef __CONTAINER_ACHIEVEMENTS
#define __CONTAINER_ACHIEVEMENTS


namespace ach
{
	enum Achievement
	{
		acMilitaryBase = 0,
		acLaunchPad,
		acCave,
		acLab,
		acForest,
		acFactory,
		acTemple,
		acDuck,
		acIsland,
		acPlumber,
		acRobot,
		acMattress,
		acTimeMachine,
		acDonation,
		acEasy,
		acNormal,
		acHard,
		acCollectGames,
		acCollectFresh,
		acCollectAll,
		acBrickOut,
		acHexagon,
		acRace,
		acSnake,
		acSimon,
		acTetris,

		acCount
	};


	struct Achievements
	{
		 Achievements();
		~Achievements();
	};
}

#endif
