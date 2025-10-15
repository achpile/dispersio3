#ifndef __CONTAINER_RECORDS
#define __CONTAINER_RECORDS


namespace ach
{
	struct Records
	{
		json_t *data;


		 Records();
		~Records();

		void save();
	};
}

#endif
