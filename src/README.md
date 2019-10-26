This folder contains the source code of the quad-solver project.

/error/ contains error.c, which handles logging all error reports to a log file called log.txt

/getIt/ contains getIt.c, which handles obtaining user input

/main/ contains main.c, which contains the program's main method

/qSolver/ contains qSolver.c, which handles solving the quadratic equation

/validate/ contains validate.c, which handles validating user input

makefile is the makefile used to compile all of the .c files in the subdirectories
    Simply running make in the top-level of src produces the executable quad-solver
    Running make clean in the top-level of src cleans the *.o files in each subdirectory
    Running make run runs the program