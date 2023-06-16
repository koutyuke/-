#include "tool1.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double devi(double data, double ave) { return data - ave; }

double cov(double *xData, double *yData, unsigned num, double xAve,
           double yAve) {
    double x, y, total = 0;
    for (int i = 0; i < num; i++) {
        x = devi(xData[i], xAve);
        y = devi(yData[i], yAve);
        total += x * y;
    }
    return total / num;
}

double sd(double *data, int num, double ave) {
    double total = 0, result = 0;
    for (int i = 0; i < num; i++) {
        total += pow(devi(data[i], ave), 2.0);
    }
    result = total / num;
    return pow(result, 0.5);
}

double ave(double *data, int num) {
    double total = 0;
    for (int i = 0; i < num; i++) {
        total += data[i];
    }

    return total / num;
}

double cor(double c, double x, double y) { return c / (x * y); }