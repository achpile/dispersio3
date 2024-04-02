#ifndef __FRAMEWORK_MISC_LIST
#define __FRAMEWORK_MISC_LIST


#define listDelete(list)          \
    for (; !(list).empty();)      \
    {                             \
        if ((list).back())        \
            delete (list).back(); \
                                  \
        (list).pop_back();        \
    }

#endif
