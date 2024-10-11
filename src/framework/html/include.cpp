#include "meta/headers.hpp"


/***********************************************************************
     * html_include_file

***********************************************************************/
void html_include_file(FILE *fp, const char *filename)
{
	FILE *inc = fopen(filename, "r");

	if (!inc)
	{
		logger->log(ach::LogLevel::llError, "Failed to include file: %s", filename);
		return;
	}

	int c;

	while ((c = fgetc(inc)) != EOF)
		fputc(c, fp);
}



/***********************************************************************
     * html_include_css

***********************************************************************/
void html_include_css(FILE *fp, const char *filename)
{
	fprintf(fp, "<STYLE type='text/css'>\n");

	html_include_file(fp, filename);

	fprintf(fp, "</STYLE>\n");
}
