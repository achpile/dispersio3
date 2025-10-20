#include "meta/headers.hpp"


/***********************************************************************
     * Cache
     * getFlag

***********************************************************************/
bool ach::Cache::getFlag(const char *name)
{
	if (!name)
		return false;

	if (!strlen(name))
		return false;

	return json_object_getv_branch_boolean(cache, "Flags.%s", name);
}



/***********************************************************************
     * Cache
     * setFlag

***********************************************************************/
void ach::Cache::setFlag(const char *name)
{
	if (!name)
		return;

	if (!strlen(name))
		return;

	records->setAchievement(pair_get_enum(name, pairAchievementFlag));

	json_object_setv_branch_boolean(cache, true, "Flags.%s", name);

	save();
	checkFlag(name);

	if (process)
		process->refresh();
}



/***********************************************************************
     * Cache
     * checkFlag

***********************************************************************/
void ach::Cache::checkFlag(const char *name)
{
	if (!strcmp(name, "MoneyDonated"))
		cash = 0;
}
