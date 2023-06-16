#include "tool2.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "tool1.h"

double angle(double c, double s) { return c / (pow(s, 2.0)); }

double intercept(double angle, double xAve, double yAve) {
    return yAve - angle * xAve;
}

double evaluation(double *y, double *x, unsigned num, double angle,
                  double intercept, double aveY) {
    double a = 0.0, b = 0.0;
    for (int i = 0; i < num; i++) {
        a += pow((y[i] - (angle * x[i] + intercept)), 2.0);
    }
    for (int i = 0; i < num; i++) {
        b += pow(devi(y[i], aveY), 2.0);
    }

    return 1 - a / b;
}