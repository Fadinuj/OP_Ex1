#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

int is_in_mandelbrot(complex double c, int N) {
    complex double z = 0;
    for (int i = 0; i < N; ++i) {
        z = z * z + c;
        if (cabs(z) > 2.0) {
            return 0; // מחוץ לקבוצה
        }
    }
    return 1; // כנראה בתוך הקבוצה
}

int main(int argc, char *argv[]) {
    if (argc < 3 || argc > 4) {
        fprintf(stderr, "Usage: %s real imag [N]\n", argv[0]);
        return 1;
    }

    double real = atof(argv[1]);
    double imag = atof(argv[2]);
    int N = (argc == 4) ? atoi(argv[3]) : 1000;

    if (N <= 0) {
        fprintf(stderr, "Invalid N value\n");
        return 1;
    }

    complex double c = real + imag * I;

    int result = is_in_mandelbrot(c, N);

    if (result)
        printf("%.4f + %.4fi is in the Mandelbrot set\n", real, imag);
    else if (N < 50)
        printf("%.4f + %.4fi is not in the Mandelbrot set – N too small, didn’t diverge\n", real, imag);
    else
        printf("%.4f + %.4fi is not in the Mandelbrot set\n", real, imag);

    return 0;
}
