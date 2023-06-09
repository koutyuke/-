#include <stdio.h>
#include <stdlib.h>

#include "readData.h"

// gcc main.c readData.c コンパイル
int main(void) {
    FILE *fp;
    Data *data;

    fp = fopen("data/data01.txt", "r");
    data = readData(fp);
    printf("%d\n", data->num);

    return 0;
}