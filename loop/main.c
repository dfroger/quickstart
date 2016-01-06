#include <stdio.h>
#include <stdlib.h>

#include "loop0.h"
#include "loop1.h"

void
version0(size_t size, size_t nloops, double* x, double* time_spent)
{
    srand(0);
    double *vx, *vy, *vz;
    create0(&vx, &vy, &vz, size);
    int iloop;
    for (iloop=0 ; iloop<nloops ; iloop++) {
        setvalues0(vx, vy, vz, size);
        compute0(vx, vy, vz, size, x, time_spent);
    }
    destroy0(vx, vy, vz);
}

void
version1(size_t size, size_t nloops, double* x, double* time_spent)
{
    srand(0);
    XYZ *xyz;
    create1(&xyz, size);
    int iloop;
    for (iloop=0 ; iloop<nloops ; iloop++) {
        setvalues1(xyz, size);
        compute1(xyz, size, x, time_spent);
    }
    destroy1(xyz);
}

int main(int argc, char** argv)
{
    if (argc != 2) {
        fprintf(stderr, "USAGE: %s SIZE\n", argv[0]);
        exit(1);
    }

    int n = atoi(argv[1]);
    int size = n*n*n;
    int nloops = 20;

    double x0,x1, time_spent0, time_spent1;

    version0(size, nloops, &x0, &time_spent0);
    version1(size, nloops, &x1, &time_spent1);

    if (x0 != x1) {
        printf("Error: x0 != x1\n");
        exit(1);
    }

    printf("%d %.6g %.6g\n", size, time_spent0, time_spent1);

    return 0;
}
