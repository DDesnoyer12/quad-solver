#include "main.h"

int main(int argc, char * argv[]){
    //this is all Daniel legacy code. Do with it what you will

    /*if(strcmp(argv[1], "--report-logs") == 0 || strcmp(argv[4], "--report-logs") == 0) {
        REPORTLOGS = 1;
    }
    if(REPORTLOGS) {
        printf("Log file generated in log-reports/");
        if(createLog() != 0) {
            printf("Error creating log file");
        }
    }*/
    
    /*if(argc > 4) {
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
    } */

    double * ans1 = malloc(sizeof(double));
    double * ans2 = malloc(sizeof(double));
    double * a = malloc(sizeof(double));
    double * b = malloc(sizeof(double));
    double * c = malloc(sizeof(double)); 


    printf("Enter a, b, and c in one line separated by a space\n");
    scanf("%lf", a);
    scanf("%lf", b);
    scanf("%lf", c);
    

    printf("%lf\n", *a);
    printf("%lf\n", *b);
    printf("%lf\n", *c);

    if(validate(a, b, c) != 0) {
        printf("(main) ERROR: There is an error with the input. Exiting. File: %s, Func: %s, Line #: %d\n", __FILE__, __func__, __LINE__);
    } else {
        int ret = qsolver(a, b, c, ans1, ans2);
        /**
         * if ret is 0: 2 roots were retrieved
         * if ret is 1: Discriminant is 0 which only provides one root
         * if ret is 2: The descriminant is negative, therefore the answer is not in the set of real numbers
         * if ret is 3: a is 0 which results in division by 0
         */
        if(ret == 0){
            printf("Solution Set: {%lf, %lf}\n", *ans1, *ans2);
        }
        else if (ret == 1){
            printf("Solution Set: {%lf}\n", *ans1);
        }
        else if (ret == 2){
            printf("Discriminant is less than 0 thus the answer is not real\n");
        }else if (ret == 3){
            printf("Error, division by 0. a cannot be 0.\n");

        }
        
    }
    
    // Free allocated memory
    free(a);
    free(b);
    free(c);
    free(ans1);
    free(ans2);
    if(REPORTLOGS) {
        closeLog();
    }
    return 0;
}
