#ifndef __FRAMEWORK_MISC_FILE
#define __FRAMEWORK_MISC_FILE


#define file_list(entry, dir)      for (std::filesystem::directory_entry entry : std::filesystem::directory_iterator(dir))

bool     file_exists(const char *path);
bool     file_is_regular(const char *path);
bool     file_is_directory(const char *path);
bool     file_is_extension(const char *path, const char *ext);
uint32_t file_checksum(const char *path);
void     file_erase(const char *path);

#endif
