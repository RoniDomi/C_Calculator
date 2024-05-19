#include "appStructure.h"

// Label widget as global variable
GtkWidget *label;

int buttonPress = 0;
char digits[17];

void displayDigits(GtkWidget *widget, gpointer data)
{
    if (buttonPress >= 16)
        buttonPress = 17;

    const char *output = gtk_button_get_label(GTK_BUTTON(widget));
    digits[buttonPress] = output[0];
    gtk_label_set_text(GTK_LABEL(label), digits);
    buttonPress++;
}

void activate(GtkApplication *app, gpointer user_data)
{
    // Calculator elements
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *grid;
    GtkWidget *box;

    // Operation buttons
    GtkWidget *addition;
    GtkWidget *subtraction;
    GtkWidget *division;
    GtkWidget *multiplication;
    GtkWidget *clear;
    GtkWidget *erase;
    GtkWidget *percent;
    GtkWidget *negSign;

    // Other helper variables
    char sNum[1];   // String that will display as button index
    int count = 1;  // Button index / face number

    // Create window with default size of 450x600
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Calculator");
    gtk_window_set_default_size(GTK_WINDOW(window), 450, 500);

    // Create a box container for number grid
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    // Center box to window
    gtk_widget_set_halign(box, GTK_ALIGN_CENTER);
    // Allow horizontal and vertical expansion
    gtk_widget_set_hexpand(box, TRUE);
    gtk_widget_set_vexpand(box, TRUE);
    gtk_window_set_child(GTK_WINDOW(window), box);

    // Create numerical input display label
    label = gtk_label_new("");
    gtk_box_append(GTK_BOX(box), label);

    // Create new grid and fill it with buttons 3x3 with an additional 0 button at the bottom
    grid = gtk_grid_new();
    // Add grid to box
    gtk_box_set_homogeneous(GTK_BOX(box), TRUE); // Homogenous == evenly distributed
    gtk_box_append(GTK_BOX(box), grid);

    for (int i = 1; i < 5; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            // Add 0 to the bottom of the grid
            if (count > 9) {
                sprintf(sNum, "%d", 0);
                button = gtk_button_new_with_label(sNum);
                gtk_widget_set_size_request(button, 70, 70);
                gtk_grid_attach(GTK_GRID(grid), button, 2, i, 1, 1);
                // Signal what button is pressed to console
                g_signal_connect(button, "clicked", G_CALLBACK(displayDigits), NULL);
                break;
            }

            // Fill grid with numbers in their respective positions
            sprintf(sNum, "%d", count);
            button = gtk_button_new_with_label(sNum);
            gtk_widget_set_size_request(button, 70, 70);
            gtk_grid_attach(GTK_GRID(grid), button, j, i, 1, 1);
            // Signal what button is pressed to console
            g_signal_connect(button, "clicked", G_CALLBACK(displayDigits), NULL);
            count++;
        }
    }

    // Create operation buttons and append them to grid
    addition = gtk_button_new_with_label("+");
    subtraction = gtk_button_new_with_label("-");
    multiplication = gtk_button_new_with_label("×");
    division = gtk_button_new_with_label("÷");
    clear = gtk_button_new_with_label("C");
    negSign = gtk_button_new_with_label("±");
    percent = gtk_button_new_with_label("%");
    erase = gtk_button_new_with_label("⌫");

    gtk_grid_attach(GTK_GRID(grid), negSign, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), percent, 2, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), erase, 3, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), clear, 4, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), addition, 4, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), subtraction, 4, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), multiplication, 4, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), division, 4, 4, 1, 1);

    gtk_window_present(GTK_WINDOW(window));
}
