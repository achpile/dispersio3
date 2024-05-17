#ifndef __FRAMEWORK_MISC_FLAG
#define __FRAMEWORK_MISC_FLAG


void flag_set    (long *value, int bit, bool flag);
void flag_check  (long *value, int bit);
void flag_uncheck(long *value, int bit);
void flag_toggle (long *value, int bit);
bool flag_get    (long  value, int bit);

#endif
