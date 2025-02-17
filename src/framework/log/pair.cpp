#include "meta/headers.hpp"


/***********************************************************************
     * pairLog

***********************************************************************/
ach::Pair<ach::LogLevel> pairLog[] =
{
	{.num = ach::LogLevel::llDebug  , .str = "DBG" },
	{.num = ach::LogLevel::llInfo   , .str = "INFO"},
	{.num = ach::LogLevel::llWarning, .str = "WARN"},
	{.num = ach::LogLevel::llError  , .str = "ERR" },

	{.num = ach::LogLevel::llDebug  , .str = NULL  },
};
