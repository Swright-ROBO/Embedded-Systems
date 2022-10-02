#include "mbed.h"
#include "Complex_C.hpp"
#include <cstdio>


// TASK - write and test complexConjugate, complexNegate, complexSubtract, complexMagnitude, complexMultiply and complexDivide

int main() {
    printf("\n\nTASK312\n");

    //Create instance of a complex number
    ComplexNumber_C p = {2.0, 3.0};
    ComplexNumber_C q = {1.0, 1.0};
    complexDisplay("p", p);
    complexDisplay("q", q);
    
    /* Adding Complex */
    printf("\nSum of Complex\n");
    ComplexNumber_C sum = complexAdd(p, q);
    complexDisplay("p+q", sum);

    /*Conjugating of Complex*/
    printf("\nConjugate of Complex\n");
    complexConjugate(p);
    complexConjugate(q);
    complexDisplay("p", p);
    complexDisplay("q", q);
    
    while (true) {
    }
}
