# quad-solver
    Quadratic Equation Solver for CIS 4900 - Senior Design

# Running the Application
## Compiling
    To compile, naviagte to the /src/ folder from within in a command line and run the command 'make'

## Running
    The application can be run in two different ways:
    ./quad-solver {a} {b} {c} (optional argument: --log)
    ./quad-solver (optional argument: --log)
    
    Passing values from the command line will run the solver for that one set of numbers and then quit.
    
    Running without any values on the command line will start a loop that allows the user to solve
    as many sets of values as they would like until they specify "Exit".

    Optional arguments:
    Adding '--log' as the final command line argument in either case will enable logging.
    Alternatively, logging can also be enabled during runtime by typing 'log' when prompted for values.

    Other:
    Typing 'help' when prompted for values will display a list of help options.

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
