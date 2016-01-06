#include <stdio.h>
#include <stdlib.h>

#include "loop0.h"
#include "loop1.h"

double
version0(size_t size)
{
    double *vx, *vy, *vz;
    srand(0);
    create0(vx, vy, vz, size);
    double x = compute0(vx, vy, vz, size);
    destroy0(vx, vy, vz);
}

double
version1(size_t size)
{
    XYZ *xyz;
    srand(0);
    create1(xyz, size);
    double x = compute1(xyz, size);
    destroy1(xyz);
}

int main(int argc, char** argv)
{
    if (argc != 2) {
        fprintf(stderr, "USAGE: %s N\n", argv[0]);
        exit(1);
    }

    int n = atoi(argv[1]);
    int size = n*n*n;

    double x0 = version0(size);
    printf("x0 = %g\n", x0);

    double x1 = version1(size);
    printf("x1 = %g\n", x1);

    return 0;
}
