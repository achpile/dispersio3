#ifndef __FRAMEWORK_MISC_HANDLER
#define __FRAMEWORK_MISC_HANDLER


namespace ach
{
	typedef void (*Handler )(void *context, json_t *);
	typedef void (*Callback)(void *context, const char *);
}

#endif
