#ifndef __META_DEFINES
#define __META_DEFINES


/***********************************************************************
     * Project

***********************************************************************/
#define PROJECT_NAME   "Dispersio 3"
#define PROJECT_VERS   "0.0.1"



/***********************************************************************
     * List processing macros

***********************************************************************/
#define listDelete(list)          \
    for (; !(list).empty();)      \
    {                             \
        if ((list).back())        \
            delete (list).back(); \
                                  \
        (list).pop_back();        \
    }

#endif
