#include "meta/headers.hpp"


/***********************************************************************
     * html_link_add

***********************************************************************/
void html_link_add(FILE *fp, const char *link)
{
	fprintf(fp, "<A href='#DM:%s'>%s</A>", link, link);
}



/***********************************************************************
     * html_link_set

***********************************************************************/
void html_link_set(FILE *fp, const char *link, const char *label)
{
	fprintf(fp, "<A name='DM:%s'>%s</A>", link, label);
}
