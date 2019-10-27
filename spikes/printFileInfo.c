#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {

    // Small spike that demonstrates the ability to print current file name, current function name, and current line number
    // Possibly will be used for error and/or test logging
    
    printf("File: %s, Func: %s, Line #: %d\n", __FILE__, __func__, __LINE__);


    return 0;
}