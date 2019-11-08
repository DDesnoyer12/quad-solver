# This folder contains the source code of the quad-solver project.

## /log/ 
   contains log.c, which handles logging all error and test reports to a log file located in /logs/

## /getIt/
   contains getIt.c, which handles obtaining user input

## /main/ 
   contains main.c, which contains the program's main method

## /qSolver/ 
   contains qSolver.c, which handles solving the quadratic equation

## /validate/ 
   contains validate.c, which handles validating user input

## /tests/ 
   contains test_qsolver.c, which performs unit tests for the qsolver function
   contains test_validate.c, which performs unit tests for the validateInput function
   contains makefile, which can be run using the command make to compile both unit test files


## makefile
is the makefile used to compile all of the .c files in the subdirectories
    Running "make" in the top-level of src produces the executable quad-solver and produces the *.o files in each subdirectory
    Running "make clean" in the top-level of src removes the *.o files in each subdirectory and removes the executable in the top folder
    Running "make run" in the top-level of src runs the program
