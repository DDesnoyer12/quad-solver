#include "log.h"
FILE * errFile;
/**
 * log.c
 * createLog() is called at the start of the program's execution and creates a log file (located in the 'logs' folder) 
 * detailing events that happen during that execution of the program. 
 * The filename of each log file is a timestamp of when the program began its execution. 
 * logLine() can be called from within any function to write an error/success/other message to the log
 * closeLog() closes the log file at the end of program execution, saving the changes made
 */
int createLog() {
    printf("%d\n", REPORTLOGS);
    REPORTLOGS = 2;
    // Timestamp struct and string buffer
    char tsBuf[40];
	time_t timestamp = time(NULL);
    // Convert timestamp to string
	strftime(tsBuf, sizeof(tsBuf), "%m-%d-%Y_%H:%M:%S", localtime(&timestamp));
    
    // Append filename (timestamp) to the folder path
    char * filepath = malloc(40);
    strcpy(filepath, "../logs/");
    strcat(filepath, tsBuf);

    // Open log file
    if((errFile = fopen(filepath, "w")) == NULL) {
        printf("Error opening/creating log file\n");
        return -1;
    }
    return 0;
}

void logLine(const char * error, ...) {
    // If log file exists, write error
    if(errFile != NULL) {
        fprintf(errFile, "%s\n", error);
    }
}

void closeLog() {
    // If log file exists, close it
    if(errFile != NULL) {
        fclose(errFile);
    }
}