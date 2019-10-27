#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "qsolver.h"

void qsolver(double * a, double * b, double* c, double * ans1, double * ans2){
    double disc = sqrt(pow(*b, 2) - 4 * (*a) * (*c));
    
    *ans1 = (-(*b) + disc)/ (2 * (*a));
    *ans2 = (-(*b) - disc)/ (2 * (*a));
}