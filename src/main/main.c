#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void solver(double * a, double * b, double* c, double * ans1, double * ans2){
    double sq = sqrt(pow(*b, 2) - 4 * (*a) * (*c));
    
    *ans1 = (-(*b) + sq)/ (2 * (*a));
    *ans2 = (-(*b) - sq)/ (2 * (*a));
    
}

int main(int argc, char * argv[]){
    double * ans1 = malloc(sizeof(double));
    double * ans2 = malloc(sizeof(double));

    double * a = malloc(sizeof(double));
    double * b = malloc(sizeof(double));
    double * c = malloc(sizeof(double));

    printf("Enter a, b, and c in order\n");
    scanf("%lf", a);
    scanf("%lf", b);
    scanf("%lf", c);

    solver(a, b, c, ans1, ans2);
    printf("Solution Set: {%lf, %lf}\n", *ans1, *ans2);


    return 0;
}
