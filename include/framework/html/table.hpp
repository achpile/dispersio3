#ifndef __FRAMEWORK_HTML_TABLE
#define __FRAMEWORK_HTML_TABLE


void html_table_start     (FILE *fp);
void html_table_row_start (FILE *fp, const char *cls  );
void html_table_data_start(FILE *fp);

void html_table_end       (FILE *fp);
void html_table_row_end   (FILE *fp);
void html_table_data_end  (FILE *fp);

void html_table_header    (FILE *fp, const char *width, const char *name);

#endif
