CC = gcc

CFLAGS = -ggdb -Wall -pedantic -std=gnu11
TARGETS := ./main/main.o ./qsolver/qsolver.o ./validate/validate.o ./log/log.o ./getit/getit.o ./help/help.o ./error/error.o

all: main

main: $(TARGETS)
	$(CC) $(CFLAGS) $(TARGETS) -o quad-solver -lm

clean: 
	rm -rf $(TARGETS) quad-solver

clear-logs:
	rm -rf ../logs/log-*

run:
	./quad-solver

test:
	./quad-solver < ../test/testfile.txt

test-1set:
	./quad-solver < ../test/test-1set.txt

test-2set:
	./quad-solver < ../test/test-2set.txt

test-bounds:
	./quad-solver < ../test/test-bounds.txt

test-inf:
	./quad-solver < ../test/test-inf.txt

test-nan:
	./quad-solver < ../test/test-nan.txt

test-norm:
	./quad-solver < ../test/test-nor.txt

test-cli:
	./quad-solver 1 5 6

test-qsolver:
	./tests/test-quadsolver

test-validate:
	./tests/test-validate


