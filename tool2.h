#include <stdio.h>

double angle(double c, double s);
double intercept(double angle, double xAve, double yAve);
double evaluation(double *y, double *x, unsigned num, double angle,
                  double intercept, double aveY);