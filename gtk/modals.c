#include "include/modals.h"

void display_error_modal(GtkWindow *window, char* error) {
	GtkDialogFlags flags = GTK_DIALOG_DESTROY_WITH_PARENT;
	GtkWidget *dialog = gtk_message_dialog_new (window, flags, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE,error);
	gtk_dialog_run (GTK_DIALOG (dialog));
	gtk_widget_destroy (dialog);
}

void display_info_modal(GtkWindow *window, char* info) {
	GtkDialogFlags flags = GTK_DIALOG_DESTROY_WITH_PARENT;
	GtkWidget *dialog = gtk_message_dialog_new (window, flags, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE,info);
	gtk_dialog_run (GTK_DIALOG (dialog));
	gtk_widget_destroy (dialog);
}
