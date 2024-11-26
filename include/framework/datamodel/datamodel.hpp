#ifndef __FRAMEWORK_DATAMODEL_DATAMODEL
#define __FRAMEWORK_DATAMODEL_DATAMODEL


namespace ach
{
	struct Datamodel
	{
		json_t *dm;
		json_t *data;
		json_t *traits;
		json_t *classes;


		 Datamodel();
		~Datamodel();

		void load();
		void loadPath(const char *path);
	};
}

#endif
