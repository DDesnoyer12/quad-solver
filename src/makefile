CC = gcc

CFLAGS = -ggdb -Wall -pedantic -std=gnu11
TARGETS := ./main/main.o ./qsolver/qsolver.o ./validate/validate.o ./error/error.o ./getit/getit.o

all: main

main: $(TARGETS)
	$(CC) $(CFLAGS) $(TARGETS) -o quad-solver -lm

clean: 
	rm -rf $(TARGETS) quad-solver
	
run:
	./quad-solver



