#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>

void menubar(GtkWidget *vbox) {
  // Menubar
    GtkWidget *menubar;
    GtkWidget *fileMenu;
    GtkWidget *openMenu;
    GtkWidget *editMenu;
    GtkWidget *sep;
    GtkWidget *fileMi;
    GtkWidget *openMi;
    GtkWidget *openProjectMi;
    GtkWidget *openSceneMi;
    GtkWidget *openTakeMi;
    GtkWidget *editMi;
    GtkWidget *quitMi;

    menubar = gtk_menu_bar_new();

    // File Menu
    fileMenu = gtk_menu_new();
    fileMi = gtk_menu_item_new_with_label("File");
        openMenu = gtk_menu_new();
	openMi = gtk_menu_item_new_with_label("Open");
	    openProjectMi = gtk_menu_item_new_with_label("Open Project");
	    openSceneMi = gtk_menu_item_new_with_label("Open Scene");
	    openTakeMi = gtk_menu_item_new_with_label("Open Take");
	    gtk_menu_item_set_submenu(GTK_MENU_ITEM(openMi), openMenu);
	    gtk_menu_shell_append(GTK_MENU_SHELL(openMenu), openProjectMi);
	    gtk_menu_shell_append(GTK_MENU_SHELL(openMenu), openSceneMi);
	    gtk_menu_shell_append(GTK_MENU_SHELL(openMenu), openTakeMi);
	    sep = gtk_separator_menu_item_new();
	    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), openMi);
	    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), sep);
    quitMi = gtk_menu_item_new_with_label("Quit");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(fileMi), fileMenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), quitMi);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), fileMi);

    // Edit Menu
    editMenu = gtk_menu_new();
    editMi = gtk_menu_item_new_with_label("Edit");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(editMi), editMenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), editMi);

    gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

    // Closes program when quit is selected
    g_signal_connect(G_OBJECT(quitMi), "activate",
		     G_CALLBACK(gtk_main_quit), NULL);

}

int main(int argc, char **argv) {
    GtkWidget *window;
    GtkWidget *vbox;
    
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Brick");
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);
    
    menubar(vbox);
    
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
