#include "meta/headers.hpp"


/***********************************************************************
     * html_section_header

***********************************************************************/
void html_section_header(FILE *fp, const char *title)
{
	fprintf(fp, "<H1>%s</H1>", title);
}



/***********************************************************************
     * html_section_subheader

***********************************************************************/
void html_section_subheader(FILE *fp, const char *title)
{
	fprintf(fp, "<H3>%s</H3>", title);
}
