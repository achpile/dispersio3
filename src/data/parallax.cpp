#include "meta/headers.hpp"


/***********************************************************************
     * DataParallax
     * constructor

***********************************************************************/
ach::DataParallax::DataParallax(json_t *obj)
{
	json_t     *layer;
	const char *key;

	json_object_foreach(json_object_get(obj, "Layers"), key, layer)
	{
		layers.push_back(new ach::Background(json_object_get_string(layer, "Image" ),
		                                     json_object_get_real  (layer, "Factor")));

		layers.back()->setSize(RENDER_LAYER_BG_X, RENDER_LAYER_BG_Y);
	}
}



/***********************************************************************
     * DataParallax
     * destructor

***********************************************************************/
ach::DataParallax::~DataParallax()
{
	list_delete(layers);
}
