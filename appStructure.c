#include "appStructure.h"

void print_console(GtkWidget *widget, gpointer data)
{
    const char *label = gtk_button_get_label(GTK_BUTTON(widget));
    g_print("Button %s pressed\n", label);
}

void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *grid;
    GtkWidget *box;
    char sNum[1];
    int count = 1;

    // Create window with default size of 500x800
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Calculator");
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 800);

    // Create a box container for number grid
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    // Center box to window
    gtk_widget_set_halign(box, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(box, GTK_ALIGN_CENTER);
    // Allow horizontal and vertical expansion
    gtk_widget_set_hexpand(box, TRUE);
    gtk_widget_set_vexpand(box, TRUE);
    gtk_window_set_child(GTK_WINDOW(window), box);

    // Create new grid and fill it with buttons 3x3 with an additional 0 button at the bottom
    grid = gtk_grid_new();
    // Add grid to box
    gtk_box_set_homogeneous(GTK_BOX(box), TRUE); // Homogenous == evenly distributed
    gtk_box_append(GTK_BOX(box), grid);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // Add 0 to the bottom of the grid
            if (count > 9) {
                sprintf(sNum, "%d", 0);
                button = gtk_button_new_with_label(sNum);
                gtk_widget_set_size_request(button, 100, 100);
                gtk_grid_attach(GTK_GRID(grid), button, 1, i, 1, 1);
                // Signal what button is pressed to console
                g_signal_connect(button, "clicked", G_CALLBACK(print_console), NULL);
                break;
            }

            // Fill grid with numbers in their respective positions
            sprintf(sNum, "%d", count);
            button = gtk_button_new_with_label(sNum);
            gtk_widget_set_size_request(button, 100, 100);
            gtk_grid_attach(GTK_GRID(grid), button, j, i, 1, 1);
            // Signal what button is pressed to console
            g_signal_connect(button, "clicked", G_CALLBACK(print_console), NULL);
            count++;
        }
    }

    gtk_window_present(GTK_WINDOW(window));
}
