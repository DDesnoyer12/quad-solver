#include "help.h"

void displayHelp() {
    printf("\nQuad-Solver Application\nAuthors: Daniel Desnoyer, Matthew Schutz, Erik Larson, Richard Schaefer\n");
    printf("Run the program from the command line by executing the ./quad-solver command within the /src/ folder.\n");
    printf("Acceptable command line arguments:\n\t./quad-solver (optional argument: --log)\n\t./quad-solver {a} {b} {c} (optional argument: --log)\n");
    printf("./quad-solver {a} {b} {c} will automatically run the solver with values provided from the command line.\n");
    printf("./quad-solver with no additional command line arguments will prompt the user to enter equations until they wish to exit.\n");
    printf("Typing 'Help' or 'help' while running the program will display this list\n");
    printf("Typing 'Log' or 'log' while running the program will enable logging.\n");
    printf("Running the program with --log as a command line argument will also enable logging.\n");
}
