#include <stdio.h>
#include <stdlib.h>

#include "readData.h"
#include "tool1.h"

// gcc main.c readData.c コンパイル

int main(void) {
    FILE *fp;
    Data *data;

    fp = fopen("data/data01.txt", "r");
    data = readData(fp);
    int N = data->num;
    double x[N], y[N], aveX, aveY, sdX, sdY, v, r;

    for (int i = 0; i < N; i++) {
        x[i] = (data->data + i)->x;
        y[i] = (data->data + i)->y;
    }

    aveX = ave(x, N);
    aveY = ave(y, N);
    sdX = sd(x, N, aveX);
    sdY = sd(y, N, aveY);
    v = cov(x, y, N, aveX, aveY);
    r = cor(v, sdX, sdY);

    printf(
        "平均(x:%lf, y:%lf)\n標準偏差(x:%lf y:%lf)\n共分散:%lf\n相関係数:%lf\n",
        aveX, aveY, sdX, sdY, v, r);

    return 0;
}