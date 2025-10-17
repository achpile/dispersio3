#ifndef __DATA_SPRITE
#define __DATA_SPRITE


namespace ach
{
	struct DataSprite : DataContent
	{
		ach::Sprite *spr;


		 DataSprite(json_t *obj);
		~DataSprite();
	};
}

#endif
