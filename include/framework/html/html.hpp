#ifndef __FRAMEWORK_HTML_HTML
#define __FRAMEWORK_HTML_HTML


void html_start     (FILE *fp);
void html_head_start(FILE *fp);
void html_body_start(FILE *fp);

void html_end       (FILE *fp);
void html_head_end  (FILE *fp);
void html_body_end  (FILE *fp);

void html_title     (FILE *fp, const char *title);

#endif
