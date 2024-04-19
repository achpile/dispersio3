#include "meta/headers.hpp"


/***********************************************************************
     * pairAction

***********************************************************************/
ach::Pair pairAction[] =
{
	{.num = ach::ControlAction::caUp   , .str = "Up"   },
	{.num = ach::ControlAction::caDown , .str = "Down" },
	{.num = ach::ControlAction::caLeft , .str = "Left" },
	{.num = ach::ControlAction::caRight, .str = "Right"},
	{.num = ach::ControlAction::caJump , .str = "Jump" },
	{.num = ach::ControlAction::caMenu , .str = "Menu" },

	{.num = ach::ControlAction::caCount, .str = NULL   },
};
