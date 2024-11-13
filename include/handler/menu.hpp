#ifndef __HANDLER_MENU
#define __HANDLER_MENU


void handler_menu_language  (void *context, json_t *data);
void handler_menu_theme     (void *context, json_t *data);
void handler_menu_fullscreen(void *context, json_t *data);
void handler_menu_audio     (void *context, json_t *data);
void handler_menu_state     (void *context, json_t *data);
void handler_menu_reset     (void *context, json_t *data);

#endif
