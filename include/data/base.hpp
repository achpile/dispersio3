#ifndef __DATA_BASE
#define __DATA_BASE


namespace ach
{
	struct Database
	{
		std::vector<ach::DataModel*> model;
		std::vector<ach::DataSheet*> sheet;


		 Database();
		~Database();

		void load();

		ach::DataModel *getModel(const char *name);
		ach::DataSheet *getSheet(const char *name);
	};
}

#endif
