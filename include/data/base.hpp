#ifndef __DATA_BASE
#define __DATA_BASE


namespace ach
{
	struct Database
	{
		std::vector<ach::DataModel*> model;


		 Database();
		~Database();

		void load();

		ach::DataModel *getModel(const char *name);
	};
}

#endif
