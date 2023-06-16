#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "tool1.h"

double sumPowXN(double *x, unsigned num, double p) {
    double result = 0.0;
    for (int i = 0; i < num; i++) {
        result += pow(x[i], p);
    }
    return result;
}

double sumPowXYN(double *x, double *y, unsigned num, double p) {
    double result = 0.0;
    for (int i = 0; i < num; i++) {
        result += pow(x[i], p) * y[i];
    }
    return result;
}

double evaluation(double *y, double *x, unsigned num, double a0, double a1,
                  double a2, double aveY) {
    double a = 0.0, b = 0.0;
    for (int i = 0; i < num; i++) {
        a += pow((y[i] - (a2 * pow(x[i], 2.0) + a1 * x[i] + a0)), 2.0);
    }
    for (int i = 0; i < num; i++) {
        b += pow(devi(y[i], aveY), 2.0);
    }
    return 1 - a / b;
}