#include "mbed.h"
#include <cstdio>

// Date Type ComplexNumber_C
typedef struct {
  double real;
  double imag;
} ComplexNumber_C;


int main() {

    //Create instance of a complex number
    ComplexNumber_C p;

    //Initialise each attribute 
    p.real = 2.0;
    p.imag = 3.0;
    printf("\nthe sum of real is %f and sum of imaginary is %f\n", p.real, p.imag);
    //Create and Initialise 
    ComplexNumber_C q = {1.0, 1.0};
    printf("\nthe sum of real is %f and sum of imaginary is %f\n", q.real, q.imag);
    // TASK:
    // Create another complex number y
    // Calculate the complex sum of p and q and store in y
    // Use printf to display as a complex number (hint: you need two placeholders)
    ComplexNumber_C y = {(q.real + p.real), (q.imag + p.imag)};

    printf("\nthe sum of real is %f and sum of imaginary is %f\n", y.real, y.imag);
    while (true) {
    }
}
