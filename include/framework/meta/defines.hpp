#ifndef __FRAMEWORK_META_DEFINES
#define __FRAMEWORK_META_DEFINES


/***********************************************************************
     * Math

***********************************************************************/
#define MATH_PI                3.1415926f
#define MATH_DEG               57.2957804904f
#define MATH_RAD               0.01745329222f

#define MATH_EPSILON           0.001f

#define SIDE_LEFT             -1
#define SIDE_MIDDLE            0
#define SIDE_RIGHT             1



/***********************************************************************
     * Menu

***********************************************************************/
#define MENU_PADDING           10
#define MENU_SPACING           5
#define MENU_THICKNESS         1
#define MENU_BOX_SHRINK        8
#define MENU_SLIDER_SIZE       5



/***********************************************************************
     * String

***********************************************************************/
#define STR_LEN_MENU           32
#define STR_LEN_NAME           128
#define STR_LEN_PATH           256
#define STR_LEN_LOG            512

#define STR_REGEX_NAME         "^[[:alnum:]_-]{1,128}$"
#define STR_REGEX_COLOR        "^#[[:xdigit:]]{2}{3,4}$"



/***********************************************************************
     * Time

***********************************************************************/
#define TIME_ANIMATION_DEFAULT 0.1f
#define TIME_MUSIC_FADE        3.0f



/***********************************************************************
     * Control

***********************************************************************/
#define CONTROL_GAMEPAD_COUNT  8
#define CONTROL_GAMEPAD_GATE   50.0f



/***********************************************************************
     * Datamodel

***********************************************************************/
#define DM_DIRECTIVE_PWD       '~'
#define DM_DIRECTIVE_START     '@'

#define DM_DIRECTIVE           "@"

#define DM_DIRECTIVE_ATTR      DM_DIRECTIVE "attr"
#define DM_DIRECTIVE_INCLUDE   DM_DIRECTIVE "include"
#define DM_DIRECTIVE_SILENT    DM_DIRECTIVE "silent"
#define DM_DIRECTIVE_DIR       DM_DIRECTIVE "dir"
#define DM_DIRECTIVE_RECURSIVE DM_DIRECTIVE "recursive"

#define DM_PATH_BASE           "data/base"

#define DM_DOCS_FILE_OUTPUT    "misc/docs/datamodel.html"
#define DM_DOCS_FILE_STYLE     "misc/docs/style.css"

#endif
