#include "meta/headers.hpp"


/***********************************************************************
     * file_checksum

***********************************************************************/
uint32_t file_checksum(const char *path)
{
	FILE *fp = fopen(path, "r");

	if (!fp)
		return 0;

	uint16_t a = 1;
	uint16_t b = 0;
	uint8_t  c;

	while (fread(&c, 1, 1, fp))
	{
		a += c;
		b += a;
	}

	return a + (b << 16);
}
