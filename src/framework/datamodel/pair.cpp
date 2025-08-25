#include "meta/headers.hpp"


/***********************************************************************
     * pairAttrType

***********************************************************************/
ach::Pair<ach::DataType> pairAttrType[] =
{
	{.num = ach::DataType::dtObject  , .str = "object"  },
	{.num = ach::DataType::dtString  , .str = "string"  },
	{.num = ach::DataType::dtInteger , .str = "integer" },
	{.num = ach::DataType::dtReal    , .str = "real"    },
	{.num = ach::DataType::dtBoolean , .str = "boolean" },
	{.num = ach::DataType::dtFilename, .str = "filename"},
	{.num = ach::DataType::dtColor   , .str = "color"   },
	{.num = ach::DataType::dtArray   , .str = "array"   },
	{.num = ach::DataType::dtMulti   , .str = "multi"   },
	{.num = ach::DataType::dtLink    , .str = "link"    },
	{.num = ach::DataType::dtEnum    , .str = "enum"    },

	{.num = ach::DataType::dtUnknown , .str = NULL      },
};



/***********************************************************************
     * pairAttrContainer

***********************************************************************/
ach::Pair<ach::ContainerType> pairAttrContainer[] =
{
	{.num = ach::ContainerType::ctSimple , .str = "simple"},
	{.num = ach::ContainerType::ctArray  , .str = "array" },
	{.num = ach::ContainerType::ctMulti  , .str = "multi" },

	{.num = ach::ContainerType::ctUnknown, .str = NULL    },
};
