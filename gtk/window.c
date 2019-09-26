#include "include/window.h"
GtkWidget *link_folder_location;
GtkWidget *save_link_location;

void selectFolder(GtkWidget *widget, gpointer data) {
	GtkWidget *fileChooserFolderSelect = gtk_file_chooser_dialog_new("Select Folder",GTK_WINDOW(gtk_widget_get_toplevel(widget)),GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER,"Cancel",GTK_RESPONSE_CANCEL,"Select Folder",GTK_RESPONSE_ACCEPT,NULL);
	int res = gtk_dialog_run(GTK_DIALOG(fileChooserFolderSelect));
	char *filename;
	if (res==GTK_RESPONSE_ACCEPT) {
		filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fileChooserFolderSelect));
		gtk_entry_set_text(GTK_ENTRY(link_folder_location),filename);
	}
	gtk_widget_destroy(fileChooserFolderSelect);
}

void saveLink(GtkWidget *widget, gpointer data) {
	GtkWidget *fileChooserFolderSelect = gtk_file_chooser_dialog_new("Select Folder",GTK_WINDOW(gtk_widget_get_toplevel(widget)),GTK_FILE_CHOOSER_ACTION_SAVE,"Cancel",GTK_RESPONSE_CANCEL,"Save Symlink",GTK_RESPONSE_ACCEPT,NULL);
	int res = gtk_dialog_run(GTK_DIALOG(fileChooserFolderSelect));
	char *filename;
	if (res==GTK_RESPONSE_ACCEPT) {
		filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fileChooserFolderSelect));
		gtk_entry_set_text(GTK_ENTRY(save_link_location),filename);
	}
	gtk_widget_destroy(fileChooserFolderSelect);
}

void createLink(GtkWidget *widget, gpointer data) {
	//This only works on unix, so check for unix compatibility
#ifndef unix
	display_error_modal(GTK_WINDOW(gtk_widget_get_toplevel(widget)),"Error: incompatible OS!");
	return;
#endif

	//Check if the target directory exists
	if( access( gtk_entry_get_text(GTK_ENTRY(link_folder_location)), F_OK ) == -1 ) {
		char *error = concat(3,"Error: file '",gtk_entry_get_text(GTK_ENTRY(link_folder_location)),"' not found!");
		display_error_modal(gtk_widget_get_toplevel(widget),error);
		free(error);
		return;
	}

	//Execute command
	char * command = concat(5,"ln -s \"",gtk_entry_get_text(GTK_ENTRY(link_folder_location)),"\" \"",gtk_entry_get_text(GTK_ENTRY(save_link_location)),"\"");
	g_print("Executing '%s'\n",command);
	if (system(command)!=0) {
		display_error_modal(gtk_widget_get_toplevel(widget),"Unknown error occured.");
	} else {
		display_info_modal(gtk_widget_get_toplevel(widget),"Successfully created symlink!");
	}
	free(command);
}

void quitApplication(GtkWidget *widget, gpointer data) {
	g_application_quit(G_APPLICATION(app));
}

void activate (GtkApplication* app, gpointer user_data) {
	GtkWidget *window;

	window = gtk_application_window_new (app);
	gtk_window_set_title (GTK_WINDOW (window), "Chainlink");
	gtk_window_set_default_size (GTK_WINDOW (window), 250, 0); //Allow GTK to expand to minimal size

	GtkWidget *button_box = gtk_vbox_new(false,0);

	GtkWidget *link_folder_button = gtk_button_new_with_label("Select folder to link...");
	
	link_folder_location = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(link_folder_location),"/path/to/folder");
	gtk_editable_set_editable(GTK_EDITABLE(link_folder_location),true);	

	GtkWidget *save_link_button = gtk_button_new_with_label("Save Link as...");

	save_link_location = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(save_link_location),"/path/to/link");
	gtk_editable_set_editable(GTK_EDITABLE(save_link_location),true);
	
	GtkWidget *spacing = gtk_hbox_new(false,0);

	GtkWidget *create_link_button = gtk_button_new_with_label("Create Link!");
	GtkWidget *cancel_button = gtk_button_new_with_label("Cancel");

	gtk_box_pack_start(GTK_BOX(button_box),link_folder_button,true,false,0);
	gtk_box_pack_start(GTK_BOX(button_box),link_folder_location,true,false,0);
	gtk_box_pack_start(GTK_BOX(button_box),save_link_button,true,false,0);
	gtk_box_pack_start(GTK_BOX(button_box),save_link_location,true,false,0);
	gtk_box_pack_start(GTK_BOX(button_box),spacing,true,false,15);
	gtk_box_pack_start(GTK_BOX(button_box),create_link_button,true,false,0);
	gtk_box_pack_start(GTK_BOX(button_box),cancel_button,true,false,0);

	gtk_container_add(GTK_CONTAINER(window),button_box);

	gtk_window_set_resizable(GTK_WINDOW(window),false);

	gtk_widget_show_all (window);

	//Connect all signals to their button
	g_signal_connect(link_folder_button,"clicked",G_CALLBACK(selectFolder),NULL);
	g_signal_connect(save_link_button,"clicked",G_CALLBACK(saveLink),NULL);
	g_signal_connect(create_link_button,"clicked",G_CALLBACK(createLink),NULL);
	g_signal_connect(cancel_button,"clicked",G_CALLBACK(quitApplication),NULL);
}

