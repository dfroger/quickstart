#include <stdlib.h>

#include "loop1.h"
#include "util.h"

void
create1(XYZ *xyz, size_t size)
{
    xyz = malloc(sizeof(XYZ)*size);

    size_t i;
    for (i=0 ; i<size ; i++) {
        xyz->x = random_number();
        xyz->y = random_number();
        xyz->z = random_number();
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
    double x =0;

    size_t i;
    for (i=0 ; i<size ; i++) {
        x += (xyz[i].x + xyz[i].y) * xyz[i].z;
    }
}
