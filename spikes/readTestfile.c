#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {

    // Spike used to demonstrate the ability to handle feeding a test file to the program from the command line
    // Possibly useful for automated testing
    // Run in the following form: ./readTestfile < testinput.txt

    char buf[512];
    char *input = malloc(sizeof(char*));

    while((input = fgets(buf, 512, stdin)) != NULL) {
        printf("%s", input);
        // Do other stuff with the line, such as validation or other testing
    }
    printf("\n");
    return 0;
}