#ifndef _GTK_MODALS_H
#define _GTK_MODALS_H

#include <gtk/gtk.h>

void display_error_modal(GtkWindow *window, char* error);
void display_info_modal(GtkWindow *window, char* info);

#endif
