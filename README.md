# quad-solver
    Quadratic Equation Solver for CIS 4900 - Senior Design

# Running the Application
## Compiling
    To compile, naviagte to the /src/ folder from within in a command line and run the command 'make'

## Running
    To quickly solve a problem, the program can be fed values from the command line if run in the following form:
    ./quad-solver {a} {b} {c}
    Alternatively, just running ./quad-solver with no extra arguments prompts the user to enter values manually
    and allows the user to solve multiple equations before the program exits.
    Additional options:
    If running from the command line, adding --log after the values will enable logging for that execution of the program:
        ./quad-solver {a} {b} {c} --log 
    If running the program normally, typing 'help' will display a list of help options, and typing 'log' will begin logging runtime events

# Directories

## /logs/
    This folder contains any logs created when running the program

## /spikes/
    This folder contains software spikes created during development of the application

## /src/
    This folder contains the program's source code

## /test/
    This folder contains test files used for the program
### Refer to a Specific Directory's ReadMe for more info on the project
