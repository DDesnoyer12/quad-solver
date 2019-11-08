#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "cunit.h"
#include "../qsolver/qsolver.h"
#include "../log/log.h"

int main(int argc, char * argv[]){
    double * ans1 = malloc(sizeof(double));
    double * ans2 = malloc(sizeof(double));
    double * a = malloc(sizeof(double));
    double * b = malloc(sizeof(double));
    double * c = malloc(sizeof(double)); 

    *a = 0;
    *b = 0;
    *c = 0;
    int retval = qsolver(a, b, c, ans1, ans2);

    assertd_eq("retval", retval, -9);

    *a = 1;
    *b = 2;
    *c = 3;
    retval = qsolver(a, b, c, ans1, ans2);

    assertd_eq("retval", retval, -10);

    *a = 1;
    *b = 5;
    *c = 6;
    retval = qsolver(a, b, c, ans1, ans2);

    assertd_eq("retval", retval, 0);
    assertf_eq("ans1", *ans1, -2.00000);
    assertf_eq("ans2", *ans2, -3.00000);

    *a = 9;
    *b = -12;
    *c = 4;
    retval = qsolver(a, b, c, ans1, ans2);

    assertd_eq("retval", retval, 1);
    assertf_eq("ans1", *ans1, 0.6666666666666666297);
    assertf_eq("ans2", *ans2, 0.6666666666666666297);



}