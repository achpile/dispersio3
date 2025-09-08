#ifndef __META_DEFINES
#define __META_DEFINES


/***********************************************************************
     * Project

***********************************************************************/
#define PROJECT_NAME          "Dispersio 3"
#define PROJECT_VERS          "0.7.7"



/***********************************************************************
     * Files

***********************************************************************/
#define FILE_SETTINGS         "settings.json"
#define FILE_CACHE            "save.json"



/***********************************************************************
     * Render manager

***********************************************************************/
#define RENDER_LAYER_BG_X     512
#define RENDER_LAYER_BG_Y     384

#define RENDER_LAYER_GAME_X   384
#define RENDER_LAYER_GAME_Y   288

#define RENDER_LAYER_GUI_X    800
#define RENDER_LAYER_GUI_Y    600



/***********************************************************************
     * Menu

***********************************************************************/
#define MENU_LOGO_OFFSET      100.0f
#define MENU_LEVEL_WIDTH      300.0f
#define MENU_LEVEL_HEIGHT     390.0f



/***********************************************************************
     * Credits

***********************************************************************/
#define CREDITS_SPEED         50.0f
#define CREDITS_LEFT          100.0f



/***********************************************************************
     * Cutscene

***********************************************************************/
#define CUTSCENE_SPEED        25.0f
#define CUTSCENE_LEFT         100.0f
#define CUTSCENE_SPACING      10.0f
#define CUTSCENE_HEIGHT       250.0f



/***********************************************************************
     * GUI

***********************************************************************/
#define GUI_MAP_CAPTION_Y     50.0f



/***********************************************************************
     * Phys

***********************************************************************/
#define PHYS_MAX_VEL          500.0f
#define PHYS_VEL_EPSILON      10.0f
#define PHYS_MIN_BOUNCE       200.0f

#define PHYS_WATER            0.6f
#define PHYS_WATER_FALL       100.0f

#define PHYS_AREA_WIDTH       384
#define PHYS_AREA_HEIGHT      288



/***********************************************************************
     * Game

***********************************************************************/
#define GAME_PLAYER_RESPAWN   1.0f
#define GAME_FRAGILE_BREAKING 0.3f



/***********************************************************************
     * Particle

***********************************************************************/
#define PARTICLE_SPARK_SIZE   1.0f
#define PARTICLE_SPLASH_SIZE  2.0f
#define PARTICLE_WIND_DENSITY 0.00163f



/***********************************************************************
     * Arcade

***********************************************************************/
#define ARCADE_SIZE           256
#define ARCADE_SQUARE         10

#define ARCADE_BORDER_WIDTH   250
#define ARCADE_BORDER_HEIGHT  200

#define ARCADE_OFFSET_X       3
#define ARCADE_OFFSET_Y       53

#define ARCADE_SNAKE_X        25
#define ARCADE_SNAKE_Y        20

#endif
