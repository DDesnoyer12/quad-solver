#include "validate.h"

int validate(double * a, double * b, double * c) {

    /*    
    if(*(a) == 0) {
        if(REPORTLOGS) {
            char * error = malloc(512);
            sprintf(error, "(validate) ERROR: a equals 0. File: %s, Func: %s, Line #: %d", __FILE__, __func__, __LINE__);
            logLine(error);
        }
        printf("(validate) ERROR: a equals 0. File: %s, Func: %s, Line #: %d\n", __FILE__, __func__, __LINE__);
        return -1;
    }

    if(sqrt(pow(*b, 2) - 4 * (*a) * (*c)) < 0) {
        printf("(validate) ERROR: b^2-4ac is negative. File: %s, Func: %s, Line #: %d\n", __FILE__, __func__, __LINE__);
        return -1;
    }
    */
    return 0;

}

int validateInput(char * input) {
    /*
    TO DO: Rewrite validation

    char * tok = strtok(input, " ");
    int numTokens = 0;
    while(tok != NULL) {
        tok = strtok(input, " ");
        numTokens++;
        printf("%s ", tok);
    }
    printf("%d\n", numTokens);

    if(numTokens != 3) {
        printf("Error: Incorrect number of arguments provided.");
    }
    */
    return 0;
} 

