#ifndef __FRAMEWORK_MISC_LIST
#define __FRAMEWORK_MISC_LIST


#define listDelete(list)                         \
    for (; !(list).empty();)                     \
    {                                            \
        if ((list).back())                       \
            delete (list).back();                \
                                                 \
        (list).pop_back();                       \
    }


#define listUpdate(list)                         \
    for (unsigned int i = 0; i < (list).size();) \
    {                                            \
        if (!(list)[i]->update())                \
        {                                        \
            delete (list)[i];                    \
            (list).erase((list).begin() + i);    \
        }                                        \
        else                                     \
        {                                        \
            i++;                                 \
        }                                        \
    }


#define listRender(list)                         \
    for (unsigned int i = 0; i < (list).size(); (list)[i++]->render())


#endif
