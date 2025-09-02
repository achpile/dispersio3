#ifndef __HANDLER_GAME
#define __HANDLER_GAME


void handler_game_resume(void *context, json_t *data);
void handler_game_revert(void *context, json_t *data);
void handler_game_pick  (void *context, json_t *data);

#endif
