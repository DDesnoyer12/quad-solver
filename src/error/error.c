#include "error.h"

/**
 * Function: printError()
 * Prints the appropriate error message based on the error number
 * returned from another function call. Each error has a unique return value
 * and no two functions should share the same error values.
 * 
 */
void printError(errorNum) {

    switch(errorNum) {

        case -9:
            printf("Error, division by 0. a cannot be 0.\n");
            break;

        case -10:
            printf("Discriminant is less than 0 thus the answer is not real\n");
            break;

        case -1:
            printf("Error in input (input = NULL)");
            break;

        case -2:
            printf("More/Less than 3 values entered. Proper format: {a} {b} {c}\n");
            break;

        case -3:
            printf("Error in input (a, b, or c is NaN)");
            break;

        case -4:
            printf("Error in input (a, b, or c is inf)");
            break;

        case -5:
            printf("Error in input (a is out of range)");
            break;

        case -6:
            printf("Error in input (b is out of range)");
            break;

        case -7:
            printf("Error in input (c is out of range)");
            break;

        case -8:
            printf("Error in input (a, b, or c is not normal)");
            break;

        default:
            print("Unspecified error within the program.");

    }
        

    // Currently unused, but maybe used for printing specific info based on error number
}