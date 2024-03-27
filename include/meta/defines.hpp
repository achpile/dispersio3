#ifndef __DEFINES
#define __DEFINES


/***********************************************************************
     * Project

***********************************************************************/
#define PROJECT_NAME   "Dispersio 3"
#define PROJECT_VERS   "v0.0.1"



/***********************************************************************
     * List processing macros

***********************************************************************/
#define deleteList(list)   for (; !(list).empty();)      \
                           {                             \
                               if ((list).back())        \
                                   delete (list).back(); \
                                                         \
                               (list).pop_back();        \
                           }

#endif
