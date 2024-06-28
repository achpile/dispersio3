#ifndef __FRAMEWORK_MISC_FILE
#define __FRAMEWORK_MISC_FILE


#define file_list(entry, dir)    for (std::filesystem::directory_entry entry : std::filesystem::directory_iterator(dir))
#define file_exists(path)        std::filesystem::exists(path)
#define file_is_regular(entry)   std::filesystem::is_regular_file(entry)
#define file_is_directory(entry) std::filesystem::is_directory(entry)

#endif
