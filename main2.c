#include <stdio.h>
#include <stdlib.h>

#include "readData.h"
#include "tool1.h"
#include "tool2.h"

int main(void) {
    FILE *fp;
    Data *data;

    fp = fopen("data/data01.txt", "r");
    data = readData(fp);
    int N = data->num;
    double x[N], y[N], aveX, aveY, sdX, sdY, c, r, a, b, r2;

    for (int i = 0; i < N; i++) {
        x[i] = (data->data + i)->x;
        y[i] = (data->data + i)->y;
    }

    aveX = ave(x, N);
    aveY = ave(y, N);
    sdX = sd(x, N, aveX);
    sdY = sd(y, N, aveY);
    c = cov(x, y, N, aveX, aveY);
    r = cor(c, sdX, sdY);

    a = angle(c, sdX);
    b = intercept(a, aveX, aveY);
    r2 = evaluation(y, x, N, a, b, aveY);

    printf("y = %lf x + %lf\nR2: %lf", a, b, r2);

    return 0;
}