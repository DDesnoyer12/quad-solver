#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
extern int REPORTLOGS;

int createLog();
void logLine(const char * error, ...);
void closeLog();