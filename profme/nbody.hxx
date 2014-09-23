#ifndef NDBODY_H_INCLUDED
#define NDBODY_H_INCLUDED

#include <math.h>

#define NDIM 3

void
gravitationnal_force(double m1, double m2, double r1[NDIM], double r2[NDIM], 
    double softening_length_2, double force[NDIM]);

void
sum_gravitationnal_force(int nparticule, int iparticule,
    double* m, double* r, double softening_length_2, double sum_force[NDIM]);

#endif
