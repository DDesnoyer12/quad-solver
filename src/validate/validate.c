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
    char log[512];
    if(LOGGING == 1) {
        sprintf(log, "Entering function validateInput() with input = %s", input);
        logLine(log);
    }

    if(input == NULL) {
        return -1;
    }
    // Convert string values to doubles and store them in a, b, and c
    int ret = sscanf(input, "%lf %lf %lf", a, b, c);

    // If more or less than 3 values were entered, return error message
    if(ret != 3) {
        return -2;
    }
    // Check if a, b, or c are nan
    if(isnan(*a) || isnan(*b) || isnan(*c)) {
        return -3;
    }
    // Check if a, b, or c are inf
    if(isinf(*a) || isinf(*b) || isinf(*c)) {
        return -4;
    }
    // Check if a is 0 or not within range
    if((*a) == 0) {
        return -5;
    } else if(((*a) > __DBL_MAX__ || (*a) < -__DBL_MAX__) && ((*a) < __DBL_MIN__ || (*a) > -__DBL_MIN__)) {
        return -5;
    }
    // Check if b is within range
    if(((*b) > __DBL_MAX__ || (*b) < -__DBL_MAX__) && ((*b) < __DBL_MIN__ || (*b) > -__DBL_MIN__)) {
        return -6;
    }
    // Check if c is within range
    if(((*c) > __DBL_MAX__ || (*c) < -__DBL_MAX__) && ((*c) < __DBL_MIN__ || (*c) > -__DBL_MIN__)) {
        return -7;
    }

    // Return 0 if successful
    return 0;
} 

