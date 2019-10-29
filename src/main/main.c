#include "main.h"

int main(int argc, char * argv[]){
    double * ans1 = malloc(sizeof(double));
    double * ans2 = malloc(sizeof(double));
    double * a = malloc(sizeof(double));
    double * b = malloc(sizeof(double));
    double * c = malloc(sizeof(double)); 
    char input[512];
    int retVal = 0;
    // If user enters values on command line, use those instead
    if(argc == 4) {
        // Concatenate values from argv (command line) to one input string
        sprintf(input, "%s %s %s", argv[1], argv[2], argv[3]);
        // Validate the input string
        if(validateInput(input, a, b, c) != 0) {
            printf("\n(main) ERROR: There is an error with the input. Exiting. File: %s, Func: %s, Line #: %d\n", __FILE__, __func__, __LINE__);
        } else {
            // If input is valid, run it through the qsolver
            retVal = qsolver(a, b, c, ans1, ans2);
            // If qsolver is successful, print the solution set, otherwise print
            // an appropriate error message
            /*
            * if ret is 0: 2 roots were retrieved
            * if ret is 1: Discriminant is 0 which only provides one root
            * if ret is 2: The descriminant is negative, therefore the answer is not in the set of real numbers
            * if ret is 3: a is 0 which results in division by 0
            */
            if(retVal == 0){
                printf("a: %f, b: %f, c: %f\n", (*a), (*b), (*c));
                printf("Solution Set: {%lf, %lf}\n", *ans1, *ans2);
            } else if (retVal == -9) {
                printf("Error, division by 0. a cannot be 0.\n");
            } else if (retVal == -10) {
                printf("Discriminant is less than 0 thus the answer is not real\n");
            } else if (retVal == -11) {
                printf("a: %f, b: %f, c: %f\n", (*a), (*b), (*c));
                printf("Solution Set: {%lf}\n", *ans1);
            }
        }
    } else {
        printf("Welcome. Type 'help' for help.\n");
        // If user doesn't enter any values on the command line,
        // prompt them for values and loop until they enter "Exit"
        while(1) {
            // Get user input using getinput function from getit.c
            retVal = getinput(input);
            // If user enters "Exit", break the loop and exit the program
            if(strstr(input, "Exit") != NULL || strstr(input, "exit") != NULL) {
                printf("Thank you for using the application\n");
                break;
            }
            // If user enters "help" or "Help", print help info form help.c
            if(strstr(input, "help") != NULL || strstr(input, "Help") != NULL) {
                // Call displayHelp() from help.c
                displayHelp();
                // Skip current iteration of the loop 
                continue;
            }
            // Validate the input string
            if(validateInput(input, a, b, c) != 0) {
                printf("\n(main) ERROR: There is an error with the input. Exiting. File: %s, Func: %s, Line #: %d\n", __FILE__, __func__, __LINE__);
            } else {
                // If input is valid, run it through the qsolver
                retVal = qsolver(a, b, c, ans1, ans2);
                // If qsolver is successful, print the solution set, otherwise print
                // an appropriate error message
                /*
                * if ret is 0: 2 roots were retrieved
                * if ret is 1: Discriminant is 0 which only provides one root
                * if ret is 2: The descriminant is negative, therefore the answer is not in the set of real numbers
                * if ret is 3: a is 0 which results in division by 0
                */
                if(retVal == 0){
                printf("a: %f, b: %f, c: %f\n", (*a), (*b), (*c));
                    printf("Solution Set: {%lf, %lf}\n", *ans1, *ans2);
                } else if (retVal == -9) {
                    printf("Error, division by 0. a cannot be 0.\n");
                } else if (retVal == -10) {
                    printf("Discriminant is less than 0 thus the answer is not real\n");
                } else if (retVal == -11) {
                printf("a: %f, b: %f, c: %f\n", (*a), (*b), (*c));
                    printf("Solution Set: {%lf}\n", *ans1);
                }
            
                
            }

        }
    }
    // Free allocated memory
    free(a);
    free(b);
    free(c);
    free(ans1);
    free(ans2);

    return 0;
}
