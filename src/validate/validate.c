#include "validate.h"

/**
 * Function: validateInput
 * Parses input (char *) for three numbers and assigns them to a, b, and c (double *)
 * 
 * input: pointer to the char array storing the user's input
 * a: double that stores value a for the quadratic formula
 * b: double that stores value b for the quadratic formula
 * c: double that stores value c for the quadratic formula
 * 
 * Return Values:
 *      0: Input is valid and was parsed successfully
 *     -1: Input is NULL
 *     -2: Input is incorrectly formatted/incorrect number of values entered
 *     -3: One or more of the inputs is not a number (NaN)
 *     -4: One or more of the inputs is infinite (inf)
 *     -5: Value a is out of range
 *     -6: Value b is out of range
 *     -7: Value c is out of range
 *     -8: One of more of the inputs is not normal
 */
int validateInput(char * input, double * a, double * b, double * c) {

    if(input == NULL) {
        printf("Error in input (input = NULL)");
        return -1;
    }
    // Convert string values to doubles and store them in a, b, and c
    int ret = sscanf(input, "%lf %lf %lf", a, b, c);

    // If more or less than 3 values were entered, return error message
    if(ret != 3) {
        printf("More/Less than 3 values entered. Proper format: {a} {b} {c}\n");
        return -2;
    }
    // Check if a, b, or c are nan
    if(isnan(*a) || isnan(*b) || isnan(*c)) {
        printf("Error in input (a, b, or c is NaN)");
        return -3;
    }
    // Check if a, b, or c are inf
    if(isinf(*a) || isinf(*b) || isinf(*c)) {
        printf("Error in input (a, b, or c is inf)");
        return -4;
    }
    // Check if a, b, and c are all normal
    if(isnormal(*a) && isnormal(*b) && isnormal(*c)) {
        // Check if a is in range of double values
        if(((*a) < __DBL_MIN__ && (*a) < -__DBL_MAX__)  || (*a) > __DBL_MAX__) {
            printf("Error in input (a is out of range)");
            return -5;
        }
        // Check if b is in range of double values
        if(((*b) < __DBL_MIN__ && (*b) < -__DBL_MAX__) || (*b) > __DBL_MAX__) {
            printf("Error in input (b is out of range)");
            return -6;
        }
        // Check if c is in range of double values
        if(((*c) < __DBL_MIN__ && (*c) < -__DBL_MAX__) || (*c) > __DBL_MAX__) {
            printf("Error in input (c is out of range)");
            return -7;
        }
        
    } else {
        printf("Error in input (a, b, or c is not normal)");
        return -8;
    }
    // Return 0 if successful
    return 0;
} 

