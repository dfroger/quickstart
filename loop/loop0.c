#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "loop0.h"
#include "util.h"

void
create0(double **vx, double **vy, double **vz, size_t size)
{
    *vx = malloc(sizeof(double)*size);
    *vy = malloc(sizeof(double)*size);
    *vz = malloc(sizeof(double)*size);

    size_t i;
    srand(0);
    for (i=0 ; i<size ; i++) {
        (*vx)[i] = random_number();
        (*vy)[i] = random_number();
        (*vz)[i] = random_number();
    }
}

void
destroy0(double *vx, double *vy, double *vz)
{
    free(vx);
    free(vy);
    free(vz);
}

double
compute0(double *vx, double *vy, double *vz, size_t size)
{
    clock_t begin, end;
    double time_spent;
    begin = clock();

    double x = 0;

    size_t i;
    for (i=0 ; i<size ; i++) {
        x += (vx[i] + vy[i]) * vz[i];
    }

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("compute0: %.4g\n", time_spent);

    return x;
}
