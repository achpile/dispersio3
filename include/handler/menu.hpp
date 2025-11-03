#ifndef __HANDLER_MENU
#define __HANDLER_MENU


void handler_menu_start       (void *context, json_t *data);
void handler_menu_training    (void *context, json_t *data);
void handler_menu_arcade      (void *context, json_t *data);
void handler_menu_achievements(void *context, json_t *data);
void handler_menu_leaderboards(void *context, json_t *data);
void handler_menu_pick        (void *context, json_t *data);

#endif
