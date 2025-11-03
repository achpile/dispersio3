#ifndef __HANDLER_OPTIONS
#define __HANDLER_OPTIONS


void handler_options_language  (void *context, json_t *data);
void handler_options_theme     (void *context, json_t *data);
void handler_options_fullscreen(void *context, json_t *data);
void handler_options_smooth    (void *context, json_t *data);
void handler_options_framerate (void *context, json_t *data);
void handler_options_audio     (void *context, json_t *data);
void handler_options_reset     (void *context, json_t *data);
void handler_options_rebind    (void *context, json_t *data);

#endif
