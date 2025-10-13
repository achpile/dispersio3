#ifndef __DATA_CONTENT
#define __DATA_CONTENT


namespace ach
{
	struct DataContent
	{
		char name[STR_LEN_NAME];


		virtual      ~DataContent() {};
		virtual void  finalize()    {};

		void setName(const char *_name);
	};
}

#endif
