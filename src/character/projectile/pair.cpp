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
     * pairImpact

***********************************************************************/
ach::Pair pairImpact[] =
{
	{.num = ach::ImpactType::itNone , .str = "none" },
	{.num = ach::ImpactType::itSpark, .str = "spark"},

	{.num = ach::ImpactType::itNone , .str = NULL   },
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
