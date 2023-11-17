#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func1(double x) {
    double mysin = sin(3 * M_PI - 2 * x);
    double mycos = cos(5 * M_PI + 2 * x);
    return 2 * pow(mysin, 2) * pow(mycos, 2);
}

double func2(double x) {
    double mysin = sin((5.0 * M_PI / 2.0) - 8 * x);
    return 0.25 - 0.25 * mysin;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value_of_x>\n", argv[0]);
        return 1;
    }

    double x = atof(argv[1]);
    double result1, result2;

    result1 = func1(x);
    result2 = func2(x);

    printf("Result z1: %lf\n", result1);
    printf("Result z2: %lf\n", result2);

    return 0;
}