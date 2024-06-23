#ifndef __DATA_BODY
#define __DATA_BODY


namespace ach
{
	enum BodyType
	{
		btNone = 0,
		btHumanoid
	};


	struct DataBody : DataContent
	{
		ach::BodyType type;

		json_t *parts;


		 DataBody(json_t *obj);
		~DataBody();
	};
}

#endif
