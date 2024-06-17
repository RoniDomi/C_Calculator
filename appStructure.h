#ifndef C_CALCULATOR_APPSTRUCTURE_H
#define C_CALCULATOR_APPSTRUCTURE_H
#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void displayDigits(GtkWidget *widget, gpointer data);
void activate(GtkApplication *app, gpointer user_data);

#endif //C_CALCULATOR_APPSTRUCTURE_H