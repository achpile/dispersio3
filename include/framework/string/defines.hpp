#ifndef __FRAMEWORK_STRING_DEFINES
#define __FRAMEWORK_STRING_DEFINES


/***********************************************************************
     * Length

***********************************************************************/
#define STR_LEN_MENU          32
#define STR_LEN_NAME          128
#define STR_LEN_PATH          256
#define STR_LEN_LOG           512



/***********************************************************************
     * Regex

***********************************************************************/
#define STR_REGEX_NAME        "^[[:alnum:]_-]{1,128}$"
#define STR_REGEX_COLOR       "^#[[:xdigit:]]{2}{3,4}$"

#endif
