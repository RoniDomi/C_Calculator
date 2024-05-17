#include "arithmetic.h"
#include <stdio.h>
#include <string.h>

// Function that handles UI printing for calculator menu
void menu() {
    char choice[] = "";
    printf("--------------- Calculator Menu ---------------\n");
    printf("For arithmetic operations enter 'A'\n");
    printf("For more advanced calculations enter 'E'\n");
    printf("To exit enter '.'\n");
    scanf("%s", &choice);

    // Call respective function to take user to respective menu based on choice
    if (strcmp(choice, "A") == 0 || strcmp(choice, "a") == 0) {
        arithmeticOperations();
    }
    else if (strcmp(choice, "E") == 0 || strcmp(choice, "e") == 0) {
        printf("E");
    }
    else if (strcmp(choice, ".") == 0) {
        printf("Exiting...");
        return;
    }
    else {
        printf("Invalid choice\n\n");
        menu();
    }
}