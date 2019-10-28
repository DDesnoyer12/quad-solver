#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char * argv[]) {

    // Spike that demonstrates the ability to create a log file with the current timestamp as the filename.
    // Write a sample message to the log file and then closes the file.
    // Will possibly be used when logging errors and other reports
    char tsBuf[40];
	time_t timestamp = time(NULL);
    // Convert timestamp to readable string
	strftime(tsBuf, sizeof(tsBuf), "%m-%d-%Y_%H:%M:%S", localtime(&timestamp));

    char * filepath = malloc(40);
    strcpy(filepath, tsBuf);

    // Open file with timestamp as filename
    FILE * errFile = fopen(filepath, "w");
    // Write message to log file
    fprintf(errFile, "%s\n", "This is a test log file.");
    // Close file
    fclose(errFile);
}