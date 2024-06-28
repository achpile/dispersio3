#ifndef __FRAMEWORK_MISC_LIST
#define __FRAMEWORK_MISC_LIST


#define list_foreach(list)                       \
    for (unsigned int i = 0; i < (list).size(); i++)


#define list_delete(list)                        \
    for (; !(list).empty();)                     \
    {                                            \
        if ((list).back())                       \
            delete (list).back();                \
                                                 \
        (list).pop_back();                       \
    }


#define list_update(list)                        \
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


#define list_render(list)                        \
    list_foreach(list) (list)[i]->render()


#endif
