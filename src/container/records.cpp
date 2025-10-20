#include "meta/headers.hpp"


/***********************************************************************
     * Records
     * constructor

***********************************************************************/
ach::Records::Records()
{
	data = json_object_get(dm->data, "Records");

	achievements = json_object_get(data, "Achievement");
	highscores   = json_object_get(data, "Highscore"  );
	leaderboards = json_object_get(data, "Time"       );
}



/***********************************************************************
     * Records
     * destructor

***********************************************************************/
ach::Records::~Records()
{
}



/***********************************************************************
     * Records
     * save

***********************************************************************/
void ach::Records::save()
{
	json_dump_file(data, FILE_RECORDS, JSON_INDENT(4) | JSON_SORT_KEYS);
	checksum->store(FILE_RECORDS);
}



/***********************************************************************
     * Records
     * setAchievement

***********************************************************************/
void ach::Records::setAchievement(ach::Achievement achievement)
{
	if (achievement == ach::Achievement::acCount)
		return;

	if (getAchievement(achievement))
		return;

	json_object_set_boolean(achievements, pair_get_string(achievement, pairAchievement), true);
	save();
}



/***********************************************************************
     * Records
     * setHighscore

***********************************************************************/
void ach::Records::setHighscore(ach::ArcadeGame game, int score)
{
	switch (game)
	{
		case ach::ArcadeGame::agBrickOut: if (score >= 100) setAchievement(ach::Achievement::acBrickOut); break;
		case ach::ArcadeGame::agHexagon : if (score >=  60) setAchievement(ach::Achievement::acHexagon ); break;
		case ach::ArcadeGame::agRace    : if (score >=  50) setAchievement(ach::Achievement::acRace    ); break;
		case ach::ArcadeGame::agSnake   : if (score >=  25) setAchievement(ach::Achievement::acSnake   ); break;
		case ach::ArcadeGame::agSimon   : if (score >=  78) setAchievement(ach::Achievement::acSimon   ); break;
		case ach::ArcadeGame::agTetris  : if (score >= 100) setAchievement(ach::Achievement::acTetris  ); break;

		default: break;
	}


	int current = getHighscore(game);

	if (current >= score)
		return;

	json_object_set_integer(highscores, pair_get_string(game, pairArcade), score);
	save();
}



/***********************************************************************
     * Records
     * setLeaderboard

***********************************************************************/
void ach::Records::setLeaderboard(const char *name, float time)
{
	setAchievement(pair_get_enum(name, pairAchievement));

	float current = getLeaderboard(name);

	if (current && current <= time)
		return;

	json_object_set_real(leaderboards, name, time);
	save();
}



/***********************************************************************
     * Records
     * getAchievement

***********************************************************************/
bool ach::Records::getAchievement(ach::Achievement achievement)
{
	return json_object_get_boolean(achievements, pair_get_string(achievement, pairAchievement));
}



/***********************************************************************
     * Records
     * getHighscore

***********************************************************************/
int ach::Records::getHighscore(ach::ArcadeGame game)
{
	return json_object_get_integer(highscores, pair_get_string(game, pairArcade));
}



/***********************************************************************
     * Records
     * getLeaderboard

***********************************************************************/
float ach::Records::getLeaderboard(const char *name)
{
	return json_object_get_real(leaderboards, name);
}
