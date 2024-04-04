#ifndef __FRAMEWORK_MISC_FILE
#define __FRAMEWORK_MISC_FILE


#define fileList(entry, dir)     for (std::experimental::filesystem::directory_entry entry : std::experimental::filesystem::directory_iterator(dir))
#define fileExists(path)         std::experimental::filesystem::exists(path)
#define fileIsRegular(entry)     std::experimental::filesystem::is_regular_file(entry)

#endif
