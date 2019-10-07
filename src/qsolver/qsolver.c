#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "qsolver.h"

void qsolver(double * a, double * b, double* c, double * ans1, double * ans2){
    double sq = sqrt(pow(*b, 2) - 4 * (*a) * (*c));
    
    *ans1 = (-(*b) + sq)/ (2 * (*a));
    *ans2 = (-(*b) - sq)/ (2 * (*a));
}