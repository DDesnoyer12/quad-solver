#include "main.h"

int main(int argc, char * argv[]){
    double * ans1 = malloc(sizeof(double));
    double * ans2 = malloc(sizeof(double));
    double * a = malloc(sizeof(double));
    double * b = malloc(sizeof(double));
    double * c = malloc(sizeof(double)); 
    char input[512];
    char log[512];
    int retval = 0;

    // If user enters values on command line, use those instead
    if(argc >= 4) {

        // Check if user enabled logging from command line
        if(strstr(argv[4], "--log") != NULL || strstr(argv[4], "--Log") != NULL) {
 
            // Call createLog() to open log file
            retval = createLog();
            if(retval != 0) {
                printError(retval);
            }
            // Set logging toggle to true
            printf("Runtime events are being logged!\n");
            logLine("Runtime events are being logged!");
            LOGGING = 1;
        }
        // Concatenate values from argv (command line) to one input string
        sprintf(input, "%s %s %s", argv[1], argv[2], argv[3]);

        retval = validateInput(input, a, b, c);
        // Validate the input string
        if(retval != 0) {
            //printf("\n(main) ERROR: There is an error with the input. Exiting. File: %s, Func: %s, Line #: %d\n", __FILE__, __func__, __LINE__);
            printError(retval);
        } else {
            // If input is valid, run it through the qsolver
            retval = qsolver(a, b, c, ans1, ans2);
            // If qsolver is successful, print the solution set, otherwise print
            // an appropriate error message
            /*
            * if ret is 0: 2 roots were retrieved
            * if ret is 1: Discriminant is 0 which only provides one root
            * if ret is 2: The descriminant is negative, therefore the answer is not in the set of real numbers
            * if ret is 3: a is 0 which results in division by 0
            */
            if(retval == 0){                    
                if(LOGGING == 1) {
                    sprintf(log, "Two roots returned from call to qsolver with a = %lf, b = %lf, c = %lf. root1 = %lf, root2 = %lf", *a, *b, *c, *ans1, *ans2);
                    logLine(log);
                }
                printf("a: %f, b: %f, c: %f\n", (*a), (*b), (*c));
                printf("Solution Set: {%lf, %lf}\n", *ans1, *ans2);
            } else if (retval == 1) {                   
                if(LOGGING == 1) {
                    sprintf(log, "One root returned from call to qsolver with a = %lf, b = %lf, c = %lf. root = %lf", *a, *b, *c, *ans1);
                    logLine(log);
                }
                printf("a: %f, b: %f, c: %f\n", (*a), (*b), (*c));
                printf("Solution Set: {%lf}\n", *ans1);
            }
        }
    } else {
        if(argc == 2) {
            if(strstr(argv[1], "--log") != NULL || strstr(argv[1], "--Log") != NULL) {
 
                // Call createLog() to open log file
                retval = createLog();
                if(retval != 0) {
                    printError(retval);
                }
                // Set logging toggle to true
                printf("Runtime events are being logged!\n");
                logLine("Runtime events are being logged!");
                LOGGING = 1;
            }
        }
        printf("Welcome. Type 'help' for help. Type 'log' to create a log file.\n");
        // If user doesn't enter any values on the command line,
        // prompt them for values and loop until they enter "Exit"
        while(1) {
            // Get user input using getinput function from getit.c
            retval = getinput(input);
            // If user enters "Exit", break the loop and exit the program
            if(strstr(input, "Exit") != NULL || strstr(input, "exit") != NULL) {                
                if(LOGGING == 1) {
                    logLine("Program exiting.");
                }
                printf("Thank you for using the application\n");
                break;
            }
            // If user enters "help" or "Help", print help info form help.c
            if(strstr(input, "help") != NULL || strstr(input, "Help") != NULL) {
                if(LOGGING == 1) {
                    logLine("Entering function: displayHelp() in help.c");
                }
                // Call displayHelp() from help.c
                displayHelp();
                // Skip the rest of the current iteration of the loop 
                continue;
            }            
            if(strstr(input, "log") != NULL || strstr(input, "Log") != NULL) {
                // If logging is already being done, don't open another log file
                if(LOGGING == 1) {
                    printf("Runtime events are already being logged!\n");
                } else {
                    // Call createLog() to open log file
                    retval = createLog();
                    if(retval != 0) {
                        printError(retval);
                    }
                    // Set logging toggle to true
                    printf("Runtime events are being logged!\n");
                    logLine("Runtime events are being logged!");
                }

                // Skip the rest of the current iteration of the loop 
                continue;
            }
            // Validate the input string
            retval = validateInput(input, a, b, c);
            if(retval != 0) {
                printError(retval);
            } else {
                // If input is valid, run it through the qsolver
                retval = qsolver(a, b, c, ans1, ans2);
                // If qsolver is successful, print the solution set, otherwise print
                // an appropriate error message
                /*
                * if ret is 0: 2 roots were retrieved
                * if ret is 1: Discriminant is 0 which only provides one root
                * if ret is 2: The descriminant is negative, therefore the answer is not in the set of real numbers
                * if ret is 3: a is 0 which results in division by 0
                */
                if(retval == 0){                   
                    if(LOGGING == 1) {
                        sprintf(log, "Two roots returned from call to qsolver with a = %lf, b = %lf, c = %lf. root1 = %lf, root2 = %lf", *a, *b, *c, *ans1, *ans2);
                        logLine(log);
                    }
                    // qsolver was successful, print both computed roots
                    printf("a: %f, b: %f, c: %f\n", (*a), (*b), (*c));
                    printf("Solution Set: {%lf, %lf}\n", *ans1, *ans2);
                } else if (retval == 1) {                   
                    if(LOGGING == 1) {
                        sprintf(log, "One root returned from call to qsolver with a = %lf, b = %lf, c = %lf. root = %lf", *a, *b, *c, *ans1);
                        logLine(log);
                    }
                    // If only one root exists, print the one root.
                    printf("a: %f, b: %f, c: %f\n", (*a), (*b), (*c));
                    printf("Solution Set: {%lf}\n", *ans1);
                } else {
                    // Call printError() function to report any errors that occurred
                    printError(retval);
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
