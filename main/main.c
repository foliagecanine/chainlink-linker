#include <gtk/gtk.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "include/arguments.h"
#include "../gtk/include/window.h"

int init_window(int argc, char *argv[]) {
	int status;
	
	app = gtk_application_new("com.foliagecanine.chainlink", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app,"activate",G_CALLBACK(activate),NULL);
	status = g_application_run (G_APPLICATION (app), argc, argv);
  	g_object_unref (app);

	return status;
}

int main(int argc, char *argv[]) {
	int argret = parse_arguments(argc,argv);	
	if (argret!=1) {
		return argret;
	}

	return init_window(argc,argv);
}
