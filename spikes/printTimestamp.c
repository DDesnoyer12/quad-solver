#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char * argv [])
{
    // Simple spike that demonstrates the ability to convert the current time to a readable string
    // Possibly will be used for error/test reporting
	char tsBuf[40];
	time_t timestamp = time(NULL);

	strftime(tsBuf, sizeof(tsBuf), "Date: %m/%d/%Y Time: %H:%M:%S", localtime(&timestamp));
	printf("%s\n", tsBuf);
	return 0;
}