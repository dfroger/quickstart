#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "loop1.h"
#include "util.h"

void
create1(XYZ **xyz, size_t size)
{
    *xyz = malloc(sizeof(XYZ)*size);
}

void
destroy1(XYZ *xyz)
{
    free(xyz);
}

void
setvalues1(XYZ *xyz, size_t size)
{
    size_t i;
    for (i=0 ; i<size ; i++) {
        xyz[i].x = random_number();
        xyz[i].y = random_number();
        xyz[i].z = random_number();
    }
}

void
compute1(XYZ *xyz, size_t size, double *x, double *time_spent)
{
    clock_t begin, end;
    begin = clock();

    size_t i;
    XYZ* it;
    for (it = xyz ; it < xyz+size ; ++it) {
        *x += (it->x + it->y) * it->z;
    }

    end = clock();
    *time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
}
