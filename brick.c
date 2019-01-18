#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>

int main(int argc, char **argv) {
    GtkWidget *window;
    GtkWidget *vbox;

    // Menubar
    GtkWidget *menubar;
    GtkWidget *fileMenu;
    GtkWidget *editMenu;
    GtkWidget *fileMi;
    GtkWidget *editMi;
    GtkWidget *quitMi;
    
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Brick");
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);
    
    menubar = gtk_menu_bar_new();
    fileMenu = gtk_menu_new();
    editMenu = gtk_menu_new();

    fileMi = gtk_menu_item_new_with_label("File");
    quitMi = gtk_menu_item_new_with_label("Quit");
    editMi = gtk_menu_item_new_with_label("Edit");

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(fileMi), fileMenu);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(editMi), editMenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), quitMi);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), fileMi);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), editMi);
    gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);
    
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
