#include <stdio.h>
#include <complex.h>
#include "mandelbrot_lib.h"

int main() {
    double real, imag;

    while (1) {
        printf("Enter real and imag (0 0 to quit): ");
        if (scanf("%lf %lf", &real, &imag) != 2) {
            fprintf(stderr, "Invalid input.\n");
            return 1;
        }

        if (real == 0 && imag == 0)
            break;

        complex double c = real + imag * I;

        if (is_in_mandelbrot(c, 1000))
            printf("%.3f + %.3fi is in the Mandelbrot set\n", real, imag);
        else
            printf("%.3f + %.3fi is not in the Mandelbrot set\n", real, imag);
    }

    return 0;
}
