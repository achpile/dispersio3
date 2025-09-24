#ifndef __DATA_CUTSCENE
#define __DATA_CUTSCENE


namespace ach
{
	struct DataCutscene : DataContent
	{
		std::vector<ach::Sprite*>  slideshow;
		ach::DataTrack            *track;

		char text [STR_LEN_NAME];


		 DataCutscene(json_t *obj);
		~DataCutscene();
	};
}

#endif
