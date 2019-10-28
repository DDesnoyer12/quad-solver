#include <stdio.h>
#include "getit.h"

char * getIt() {

    printf("getit");
    if(REPORTLOGS) {
    char buffer[512];
    sprintf(buffer, "File: %s Function: %s Line #: %d\nCall to getIt() returning input: %s\n", __FILE__, __func__, __LINE__, buffer);
    
        logLine(buffer);
    }

    // TO DO: Get user input line here and return it
    return NULL;
}