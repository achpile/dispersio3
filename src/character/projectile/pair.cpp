#include "meta/headers.hpp"


/***********************************************************************
     * pairTracer

***********************************************************************/
ach::Pair pairTracer[] =
{
	{.num = ach::TracerType::ttNone , .str = "none" },
	{.num = ach::TracerType::ttLine , .str = "line" },
	{.num = ach::TracerType::ttSmoke, .str = "smoke"},

	{.num = ach::TracerType::ttNone , .str = NULL   },
};



/***********************************************************************
     * pairEffect

***********************************************************************/
ach::Pair pairEffect[] =
{
	{.num = ach::EffectType::etNone , .str = "none" },
	{.num = ach::EffectType::etSpark, .str = "spark"},

	{.num = ach::EffectType::etNone , .str = NULL   },
};



/***********************************************************************
     * pairOrient

***********************************************************************/
ach::Pair pairOrient[] =
{
	{.num = ach::OrientType::otNone     , .str = "none"     },
	{.num = ach::OrientType::otDirection, .str = "direction"},
	{.num = ach::OrientType::otRotation , .str = "rotation" },

	{.num = ach::OrientType::otNone     , .str = NULL       },
};
