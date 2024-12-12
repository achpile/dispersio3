#ifndef __DATA_PARALLAX
#define __DATA_PARALLAX


namespace ach
{
	struct DataParallax : DataContent
	{
		std::vector<ach::Background*> layers;


		 DataParallax(json_t *obj);
		~DataParallax();
	};
}

#endif
