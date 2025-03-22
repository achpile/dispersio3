#include "meta/headers.hpp"


/***********************************************************************
     * LanguageManager
     * constructor

***********************************************************************/
ach::LanguageManager::LanguageManager()
{
}



/***********************************************************************
     * LanguageManager
     * destructor

***********************************************************************/
ach::LanguageManager::~LanguageManager()
{
}



/***********************************************************************
     * LanguageManager
     * get

***********************************************************************/
sf::String ach::LanguageManager::get(const char *path)
{
	json_t *token = json_object_get_branch(data, path);

	if (!token)
	{
		logger->log(ach::LogLevel::llError, "Language token '%s' is not found", path);
		return "";
	}

	if (!json_is_string(token))
	{
		logger->log(ach::LogLevel::llError, "Language token '%s' is not string", path);
		return "";
	}

	return str_utf8(json_string_value(token));
}



/***********************************************************************
     * LanguageManager
     * getv

***********************************************************************/
sf::String ach::LanguageManager::getv(const char *format, ...)
{
	char path[STR_LEN_PATH];

	va_list ap;

	va_start(ap, format);
	vsnprintf(path, STR_LEN_PATH, format, ap);
	va_end(ap);

	return get(path);
}



/***********************************************************************
     * LanguageManager
     * refresh

***********************************************************************/
void ach::LanguageManager::refresh()
{
	data = json_object_getv_branch(dm->data, "Translation.%s.Tokens", settings->getLanguage());
}
