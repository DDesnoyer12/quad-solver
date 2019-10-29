#include <stdio.h>
#include "getit.h"

int getinput(char * input) {

    printf("\nEnter a, b, and c in one line separated by a space, or 'Exit' to quit.\n");
    char * ret = fgets(input, 512, stdin);

    if(ret == NULL) {
        return -1;
    }
    // TO DO: Get user input line here and return it
    return 0;
}