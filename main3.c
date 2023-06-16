#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "readData.h"
#include "tool1.h"
#include "tool3.h"

int main(void) {
    FILE *fp;
    Data *data;

    fp = fopen("data/mileage.txt", "r");
    data = readData(fp);
    int N = data->num;
    double x[N], y[N], x1, x2, x3, x4, y1, xy, x2y, a, a0, a1, a2, n, r2, aveY;

    for (int i = 0; i < N; i++) {
        x[i] = (data->data + i)->x;
        y[i] = (data->data + i)->y;
    }

    x1 = sumPowXN(x, N, 1.0);
    x2 = sumPowXN(x, N, 2.0);
    x3 = sumPowXN(x, N, 3.0);
    x4 = sumPowXN(x, N, 4.0);
    y1 = sumPowXN(y, N, 1.0);
    xy = sumPowXYN(x, y, N, 1.0);
    x2y = sumPowXYN(x, y, N, 2.0);

    n = (double)N;

    aveY = ave(y, N);

    a = 2.0 * x1 * x2 * x3 + n * x2 * x4 - pow(x1, 2.0) * x4 -
        n * pow(x3, 2.0) - pow(x2, 3.0);

    a0 = (-pow(x2, 2.0) * x2y + x1 * x3 * x2y - x1 * x4 * xy + x2 * x3 * xy -
          pow(x3, 2.0) * y1 + x2 * x4 * y1) /
         a;

    a1 = (x1 * x2 * x2y - n * x3 * x2y + n * x4 * xy - pow(x2, 2.0) * xy +
          x2 * x3 * y1 - x1 * x4 * y1) /
         a;
    a2 = (n * x2 * x2y - pow(x1, 2.0) * x2y + x1 * x2 * xy - n * x3 * xy +
          x1 * x3 * y1 - pow(x2, 2.0) * y1) /
         a;

    r2 = evaluation(y, x, N, a0, a1, a2, ave(y, N));

    printf("y = %lf x^2 + %lf x + %lf\nR2: %lf", a2, a1, a0, r2);
    return 0;
}