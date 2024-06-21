#ifndef __FRAMEWORK_MISC_FILE
#define __FRAMEWORK_MISC_FILE


#define fileList(entry, dir)     for (std::filesystem::directory_entry entry : std::filesystem::directory_iterator(dir))
#define fileExists(path)         std::filesystem::exists(path)
#define fileIsRegular(entry)     std::filesystem::is_regular_file(entry)

#endif
