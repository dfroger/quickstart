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
}

void
destroy0(double *vx, double *vy, double *vz)
{
    free(vx);
    free(vy);
    free(vz);
}

void
setvalues0(double *vx, double *vy, double *vz, size_t size)
{
    size_t i;
    for (i=0 ; i<size ; i++) {
        vx[i] = random_number();
        vy[i] = random_number();
        vz[i] = random_number();
    }
}

void
compute0(double *vx, double *vy, double *vz, size_t size, double *x, double *time_spent)
{
    clock_t begin, end;
    begin = clock();

    size_t i;
    for (i=0 ; i<size ; i++) {
        *x += (vx[i] + vy[i]) * vz[i];
    }

    end = clock();
    *time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
}
