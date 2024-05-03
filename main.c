#include <stdio.h>
#include <string.h>

// Function that handles inputs for simple operations involving + - * /
void arithmeticOperations() {
    printf("\n\n\n--------------- Arithmetic ---------------\n");
    printf("Enter one number and operator at a time!\n*Press '=' to see results. \n");

    char operation[] = "";
    double initialNum = 0;

    printf("Nr: ");
    scanf("%lf", &initialNum); // Get first number

    while(1) {
        printf("Operator: ");
        scanf("%s", &operation); // Get arithmetic operator

        // Check if user requested termination of operations
        if (strcmp(operation, "=") == 0) {
            printf("Total = %.5lf\n", initialNum);
            return;
        }

        // Get next number
        double currentNum = 0;
        printf("Next nr: ");
        scanf("%lf", &currentNum);

        // Based on entered operation update value
        if (strcmp(operation, "+") == 0) {
            initialNum += currentNum;
        }
        else if (strcmp(operation, "-") == 0) {
            initialNum -= currentNum;
        }
        else if (strcmp(operation, "*") == 0) {
            initialNum *= currentNum;
        }
        else if (strcmp(operation, "/") == 0) {
            initialNum /= currentNum;
        }
        else {
            printf("Invalid operator entered!");
        }
    }
}

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

int main(void) {
    menu();

    return 0;
}