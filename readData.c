#include "readData.h"

#include <stdio.h>
#include <stdlib.h>

Data *readData(FILE *fp) {
    Data *in;
    int num;
    if ((in = (Data *)malloc(sizeof(Data))) == NULL) {
        fputs("readData error 1\n", stderr);
        exit(EXIT_FAILURE);
    }
    if (fscanf(fp, "%d", &(in->num)) != 1) {
        fputs("readData error 2\n", stderr);
        exit(EXIT_FAILURE);
    }
    if ((in->data = (Datum *)malloc(sizeof(Datum) * in->num)) == NULL) {
        fputs("readData error 3\n", stderr);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < in->num; i++) {
        double x, y;
        if (fscanf(fp, "%lf %lf", &x, &y) != 2) {
            fputs("readData error 4\n", stderr);
            exit(EXIT_FAILURE);
        }
        in->data[i].x = x;
        in->data[i].y = y;
    }
    return in;
}