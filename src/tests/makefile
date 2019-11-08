CC = gcc
CFLAGS = -ggdb -Wall -pedantic -std=gnu11

all: testqsolver testvalidate

testvalidate: 
	$(CC) $(CFLAGS) test_validate.c ../validate/validate.o ../log/log.o -o testvalidate -lm

testqsolver: 
	$(CC) $(CFLAGS) test_qsolver.c ../qsolver/qsolver.o ../log/log.o -o testqsolver -lm

test-qsolver:
	./testqsolver

test-validate:
	./testvalidate

clean:
	rm -rf testqsolver testvalidate