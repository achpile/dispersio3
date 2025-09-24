#ifndef __DATA_TRACK
#define __DATA_TRACK


namespace ach
{
	struct DataTrack : DataContent
	{
		char filename[STR_LEN_PATH];
		bool loop;


		 DataTrack(json_t *obj);
		~DataTrack();
	};
}

#endif
