#ifndef __META_DEFINES
#define __META_DEFINES


/***********************************************************************
     * Project

***********************************************************************/
#define PROJECT_NAME          "Dispersio 3"
#define PROJECT_VERS          "0.3.0"



/***********************************************************************
     * Files

***********************************************************************/
#define FILE_SETTINGS         "settings.json"
#define PATH_BASE             "data/base"



/***********************************************************************
     * Render manager

***********************************************************************/
#define RENDER_LAYER_BG_X     512
#define RENDER_LAYER_BG_Y     384

#define RENDER_LAYER_GAME_X   320
#define RENDER_LAYER_GAME_Y   240

#define RENDER_LAYER_GUI_X    800
#define RENDER_LAYER_GUI_Y    600



/***********************************************************************
     * Start screen

***********************************************************************/
#define START_FADE_SLOPE      1.0f
#define START_FADE_LENGTH     2.0f



/***********************************************************************
     * Credits screen

***********************************************************************/
#define CREDITS_SPEED         50.0f
#define CREDITS_LEFT          100.0f



/***********************************************************************
     * Menu screen

***********************************************************************/
#define MENU_LOGO_OFFSET      100



/***********************************************************************
     * Phys

***********************************************************************/
#define PHYS_GRAVITY          1000.0f
#define PHYS_MAX_VEL          2000.0f



/***********************************************************************
     * Game

***********************************************************************/
#define GAME_PLAYER_RESPAWN   3.0f



/***********************************************************************
     * Particle

***********************************************************************/
#define PARTICLE_SPARK_SIZE   1.0f

#define PARTICLE_BLOOD_SIZE   2.0f
#define PARTICLE_BLOOD_LIFE   10.0f
#define PARTICLE_BLOOD_CLEAR  9.0f
#define PARTICLE_BLOOD_SPEED  200.0f

#define PARTICLE_CHUNK_SIZE   8.0f

#endif
