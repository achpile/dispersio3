#include "meta/headers.hpp"


/***********************************************************************
     * str_utf8_iterate

***********************************************************************/
static void str_utf8_iterate(std::string::const_iterator& it, std::string::const_iterator last)
{
	if (it == last)
		return;

	unsigned char c;
	size_t res = 1;

	for (++it; last != it; ++it, ++res)
	{
		c = *it;

		if (!(c&0x80) || ((c&0xC0) == 0xC0))
			break;
	}

	return;
}



/***********************************************************************
     * str_utf8_len

***********************************************************************/
int str_utf8_len(std::string str)
{
	int res = 0;

	for (std::string::const_iterator it = str.begin(); it != str.end(); str_utf8_iterate(it, str.end()))
		res++;

	return res;
}



/***********************************************************************
     * str_utf8

***********************************************************************/
sf::String str_utf8(std::string str)
{
	return sf::String::fromUtf8(str.begin(), str.end());
}
