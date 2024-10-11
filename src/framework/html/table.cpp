#include "meta/headers.hpp"


/***********************************************************************
     * html_table_start

***********************************************************************/
void html_table_start(FILE *fp)
{
	fprintf(fp, "<TABLE width='50%%' border='1' cellpadding='2' cellspacing='0'>\n");
	fprintf(fp, "<TBODY>\n");
}



/***********************************************************************
     * html_table_row_start

***********************************************************************/
void html_table_row_start(FILE *fp, const char *cls)
{
	fprintf(fp, "<TR class='%s'>\n", cls);
}



/***********************************************************************
     * html_table_data_start

***********************************************************************/
void html_table_data_start(FILE *fp)
{
	fprintf(fp, "<TD>");
}



/***********************************************************************
     * html_table_end

***********************************************************************/
void html_table_end(FILE *fp)
{
	fprintf(fp, "</TBODY>\n");
	fprintf(fp, "</TABLE>\n");
}



/***********************************************************************
     * html_table_row_end

***********************************************************************/
void html_table_row_end(FILE *fp)
{
	fprintf(fp, "</TR>\n");
}



/***********************************************************************
     * html_table_data_end

***********************************************************************/
void html_table_data_end(FILE *fp)
{
	fprintf(fp, "</TD>\n");
}



/***********************************************************************
     * html_table_header

***********************************************************************/
void html_table_header(FILE *fp, const char *width, const char *name)
{
	fprintf(fp, "<TH width='%s%%'>%s</TH>\n", width, name);
}
