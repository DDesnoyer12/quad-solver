#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "qsolver.h"
/**
 *   Function: qsolver
 *   Computes the roots using a, b, and c, and stores them in ans1 and ans2
 *   Return values:
 *    0 - roots were computed successfully with no error
 *   -9 - equation is not a true quadratic equation/is a linear equation (a == 0)
 *  -10 - no real roots exist
 *  -11 - only one root exists (Not an error, but needed for proper output)
 */
int qsolver(double * a, double * b, double* c, double * ans1, double * ans2){
    if((*a) == 0) {
        // Equation is not a true quadratic equation
        return -9;
    }
    double disc = pow(*b, 2) - 4 * (*a) * (*c);
    if(disc < 0) {
        //fprintf(errFile,"   disc = %24.19g\n", disc);
        return -10;
    }
    if(disc == 0){
        *ans1 = (-(*b))/ (2 * (*a));
        *ans2 = *ans1;
        return -11;
    }

    *ans1 = (-(*b) + sqrt(disc))/ (2 * (*a));
    *ans2 = (-(*b) - sqrt(disc))/ (2 * (*a));

    return 0;
}