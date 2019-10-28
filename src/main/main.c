#include "main.h"

int main(int argc, char * argv[]){
    if(strcmp(argv[1], "--report-logs") == 0 || strcmp(argv[4], "--report-logs") == 0) {
        REPORTLOGS = 1;
    }
    if(REPORTLOGS) {
        printf("Log file generated in log-reports/");
        if(createLog() != 0) {
            printf("Error creating log file");
        }
    }

    double * ans1 = malloc(sizeof(double));
    double * ans2 = malloc(sizeof(double));
    double * a = malloc(sizeof(double));
    double * b = malloc(sizeof(double));
    double * c = malloc(sizeof(double));

    char * input = malloc(513);
    char buf[512];
    printf("For help, type \"help\"\n");
    printf("Enter a, b, and c separated by spaces, or 'Quit' to quit:\n");
 

    /*
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


        printf("Enter a, b, and c in one line separated by a space\n");
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
    */
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
