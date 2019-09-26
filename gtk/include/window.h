#ifndef _GTK_WINDOW_H
#define _GTK_WINDOW_H

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "../../libs/include/concat.h"
#include "../../gtk/include/modals.h"

GtkApplication *app;
void activate (GtkApplication* app, gpointer user_data);

#endif
