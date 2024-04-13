#include "meta/headers.hpp"


/***********************************************************************
     * pairAttrType

***********************************************************************/
ach::Pair pairAttrType[] = {
	{.num = ach::JSONtype::jtObject  , .str = "object"  },
	{.num = ach::JSONtype::jtString  , .str = "string"  },
	{.num = ach::JSONtype::jtInteger , .str = "integer" },
	{.num = ach::JSONtype::jtBoolean , .str = "boolean" },
	{.num = ach::JSONtype::jtFilename, .str = "filename"},
	{.num = ach::JSONtype::jtColor   , .str = "color"   },
	{.num = ach::JSONtype::jtArray   , .str = "array"   },
	{.num = ach::JSONtype::jtMulti   , .str = "multi"   },
	{.num = ach::JSONtype::jtLink    , .str = "link"    },

	{.num = ach::JSONtype::jtUnknown , .str = NULL      },
};
