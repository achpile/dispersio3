#ifndef __FRAMEWORK_MISC_FILE
#define __FRAMEWORK_MISC_FILE


#define file_list(entry, dir)      for (std::filesystem::directory_entry entry : std::filesystem::directory_iterator(dir))
#define file_exists(path)          (access(path, F_OK) == 0)
#define file_extension(entry, ext) (entry.path().extension() == ext)

bool     file_is_regular(const char *path);
bool     file_is_directory(const char *path);
uint32_t file_checksum(const char *path);
void     file_erase(const char *path);

#endif
