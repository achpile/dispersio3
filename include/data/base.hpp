#ifndef __DATA_BASE
#define __DATA_BASE


namespace ach
{
	struct Database
	{
		std::vector<ach::DataSheet*> sheet;
		std::vector<ach::DataModel*> model;


		 Database();
		~Database();

		void load();

		ach::DataSheet *getSheet(const char *name);
		ach::DataModel *getModel(const char *name);
	};
}

#endif
