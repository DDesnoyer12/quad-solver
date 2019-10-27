#include "validate.h"

int validate(double * a, double * b, double * c) {

    
    if(*(a) == 0) {
        printf("(validate) ERROR: a equals 0. File: %s, Func: %s, Line #: %d\n", __FILE__, __func__, __LINE__);
        return -1;
    }

    if(sqrt(pow(*b, 2) - 4 * (*a) * (*c)) < 0) {
        printf("(validate) ERROR: b^2-4ac is negative. File: %s, Func: %s, Line #: %d\n", __FILE__, __func__, __LINE__);
        return -1;
    }

    return 0;

}

int validateCLIArgs(int argc, char * argv[]) {

    if(!isdigit(*argv[1]) || !isdigit(*argv[2]) || !isdigit(*argv[3])) {
        printf("(validateCLI) ERROR: One or more of the arguments are not numbers. File: %s, Func: %s, Line #: %d\n", __FILE__, __func__, __LINE__);
        return -1;
    }

    return 0;

}