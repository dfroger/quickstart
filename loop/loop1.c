#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "loop1.h"
#include "util.h"

void
create1(XYZ **xyz, size_t size)
{
    *xyz = malloc(sizeof(XYZ)*size);

    size_t i;
    srand(0);
    for (i=0 ; i<size ; i++) {
        (*xyz)[i].x = random_number();
        (*xyz)[i].y = random_number();
        (*xyz)[i].z = random_number();
    }
}

void
destroy1(XYZ *xyz)
{
    free(xyz);
}

double
compute1(XYZ *xyz, size_t size)
{
    clock_t begin, end;
    double time_spent;
    begin = clock();

    double x = 0;

    size_t i;
    for (i=0 ; i<size ; i++) {
        x += (xyz[i].x + xyz[i].y) * xyz[i].z;
    }

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("compute1: %.4g\n", time_spent);

    return x;
}
