#ifndef LOG_H
#define LOH_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
extern int LOGGING;

int createLog();
void logLine(char * error);
void closeLog();

#endif