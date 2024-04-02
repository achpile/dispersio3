#ifndef __FRAMEWORK_MISC_FLAG
#define __FRAMEWORK_MISC_FLAG


void flag_set   (unsigned int *value, int bit);
void flag_unset (unsigned int *value, int bit);
void flag_toggle(unsigned int *value, int bit);
bool flag_check (unsigned int  value, int bit);

#endif
