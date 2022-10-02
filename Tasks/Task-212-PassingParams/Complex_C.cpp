#include "stdio.h"
#include "Complex_C.hpp"

ComplexNumber_C complexAdd(const ComplexNumber_C a, const ComplexNumber_C b) {
    ComplexNumber_C y = a;
    y.real += b.real;
    y.imag += b.imag;
    return y;
}

ComplexNumber_C complexConjugate(ComplexNumber_C a)
{
    a.real = -a.real;
    a.imag = -a.imag;
    return a;
}


void complexDisplay(const char *strName, const ComplexNumber_C u) {
    printf("%s = %f + j%f\n", strName, u.real, u.imag);
}

