#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "qsolver.h"
/*
    qsolver function - computes the roots using a, b, and c, and stores them in ans1 and ans2
    Return values:
    0 - roots were computed successfully with no error
    1 - equation is not a true quadratic equation/is a linear equation (a == 0)
    2 - no real roots exist

*/
int qsolver(double * a, double * b, double* c, double * ans1, double * ans2){
    // TO DO: Finish qsolver method
    if((*a) == 0) {
        // Equation is not a true quadratic equation
        //fprintf(errFile, "File: %s, Func: %s, Line #: %d\n", __FILE__, __func__, __LINE__);
        //fprintf(errFile, "\tError: %s\n", "a == 0, equation is not a true quadratic equation");
        return 3;
    }
    double disc = pow(*b, 2) - 4 * (*a) * (*c);
    if(disc < 0) {
        //fprintf(errFile,"   disc = %24.19g\n", disc);
        return 2;
    }
    if(disc == 0){
        *ans1 = (-(*b))/ (2 * (*a));
        *ans2 = *ans1;
        return 1;
    }

    *ans1 = (-(*b) + disc)/ (2 * (*a));
    *ans2 = (-(*b) - disc)/ (2 * (*a));

    return 0;
}