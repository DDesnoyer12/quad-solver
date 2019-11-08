#include "log.h"
FILE * errFile;

/**
 * Function: createLog()
 * This function is called if the user specifies that they wish to report a log of the program's runtime events.
 * It creates a log file in the quad-solver/logs/ folder with the filename being the current timestamp. All events
 * will get logged to that file for viewing after the program terminates.
 * Return Values:
 *   0 - Log file was created successfully
 *  -1 - Log file was unable to be opened/created
 */
int createLog() {

    // Timestamp struct and string buffer
    char tsBuf[40];
	time_t timestamp = time(NULL);
    // Convert timestamp to string
	strftime(tsBuf, sizeof(tsBuf), "%m-%d-%Y_%H:%M:%S", localtime(&timestamp));
    
    // Append filename (timestamp) to the folder path
    char * filepath = malloc(40);
    strcpy(filepath, "../logs/log-");
    strcat(filepath, tsBuf);

    // Open log file
    if((errFile = fopen(filepath, "w")) == NULL) {
        printf("Error opening/creating log file\n");
        return -12;
    }
    LOGGING = 1;
    return 0;
}

/**
 * Function: logLine(const char * error)
 * This function takes a string as input and writes it to the log file
 * Return Values
 *      None
 */
void logLine(char * error) {
    // If log file exists, write error
    if(errFile != NULL) {
        fprintf(errFile, "%s\n", error);
    }
}

/**
 * Function: closeLog()
 * This function closes the log file
 * Return Values
 *      None
 */
void closeLog() {
    // If log file exists, close it
    if(errFile != NULL) {
        fclose(errFile);
    }
}