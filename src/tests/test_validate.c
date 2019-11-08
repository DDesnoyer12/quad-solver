#include <stdio.h>
#include <string.h>
#include "cunit.h"
#include "../validate/validate.h"
#include "../log/log.h"

int main() {

    double * a = malloc(sizeof(double));
    double * b = malloc(sizeof(double));
    double * c = malloc(sizeof(double));

    char input[30] = "1 5 6";
    int retval = validateInput(input, a, b, c);
    
    assertd_eq("retval", retval, 0);

    strcpy(input, "a b c");
    retval = validateInput(input, a, b, c);

    assertd_eq("retval", retval, -2);

    strcpy(input, "1 5");
    retval = validateInput(input, a, b, c);

    assertd_eq("retval", retval, -2);

    strcpy(input, "NAN 5 6");
    retval = validateInput(input, a, b, c);

    assertd_eq("retval", retval, -3);

    strcpy(input, "1 inf 6");
    retval = validateInput(input, a, b, c);

    assertd_eq("retval", retval, -4);

    strcpy(input, "0 5 6");
    retval = validateInput(input, a, b, c);

    assertd_eq("retval", retval, -5);

    strcpy(input, "9007199254740993 5 6");
    retval = validateInput(input, a, b, c);

    assertd_eq("retval", retval, 0);

    return 0;
}