#ifndef __FRAMEWORK_DATAMODEL_BASE
#define __FRAMEWORK_DATAMODEL_BASE


namespace ach
{
	struct Datamodel
	{
		json_t *dm;
		json_t *data;


		 Datamodel();
		~Datamodel();

		void load();
		void loadPath(const char *path);
	};
}

#endif
