#include <stdio.h>
#include "getit.h"
int loggingStatus;
char * getIt() {

    printf("getit");

    char buffer[512];
    sprintf(buffer, "File: %s Function: %s Line #: %d\nCall to getIt() returning input: %s\n", __FILE__, __func__, __LINE__, buffer);
    logLine(buffer);
    char * ret = malloc(512);
    strcpy(ret, buffer);
    return ret;
}