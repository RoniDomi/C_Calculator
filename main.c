#include <stdio.h>
#include <string.h>

// Function that handles inputs for simple operations involving + - * /
void arithmeticOperations() {
    printf("here");
}

// Function that handles UI printing for calculator menu
void menu() {
    char choice[] = "";
    printf("--------------- Calculator Menu ---------------\n");
    printf("For arithmetic operations enter 'A'\n");
    printf("For more advanced calculations enter 'E'\n");
    printf("To exit enter '.'\n");
    scanf("%s", &choice);

    if (strcmp(choice, "A") == 0 || strcmp(choice, "a") == 0) {
        arithmeticOperations();
    }
    else if (strcmp(choice, "E") == 0 || strcmp(choice, "e") == 0) {
        printf("E");
    }
    else if (strcmp(choice, ".") == 0) {
        return;
    }
    else {
        printf("Invalid choice\n\n");
        menu();
    }
}

int main(void) {
    menu();

    return 0;
}