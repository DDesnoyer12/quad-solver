#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../qsolver/qsolver.h"
#include "../validate/validate.h"

int main(int argc, char * argv[]){

    
    double * ans1 = malloc(sizeof(double));
    double * ans2 = malloc(sizeof(double));
    double * a = malloc(sizeof(double));
    double * b = malloc(sizeof(double));
    double * c = malloc(sizeof(double));
    if(argc > 4) {
        printf("(main) ERROR: Too many arguments. File: %s, Func: %s, Line #: %d", __FILE__, __func__, __LINE__);
        exit(-1);
    }
    if(argc == 4) {
        if(validateCLIArgs(argc, argv) != 0) {
            printf("(main) ERROR: Error in CLI arguments. File: %s, Func: %s, Line #: %d", __FILE__, __func__, __LINE__);
            exit(-1);
        } else {
            *(a) = atof(argv[1]);
            *(b) = atof(argv[2]);
            *(c) = atof(argv[3]);
        }
    } else {

        /*
            Known Issue: Entering letter values here defaults the value to 0.0, rather than crashing the program.
            Example: Entering a b c as values yields 0.000000 for each variable.
        */
        printf("Enter a, b, and c in order\n");
        scanf("%lf", a);
        scanf("%lf", b);
        scanf("%lf", c);
    }

    printf("%lf\n", *a);
    printf("%lf\n", *b);
    printf("%lf\n", *c);

    if(validate(a, b, c) != 0) {
        printf("(main) ERROR: There is an error with the input. Exiting. File: %s, Func: %s, Line #: %d\n", __FILE__, __func__, __LINE__);
    } else {
        qsolver(a, b, c, ans1, ans2);
        printf("Solution Set: {%lf, %lf}\n", *ans1, *ans2);
    }

    return 0;
}
