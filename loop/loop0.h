#ifndef LOOP0_H_INCLUDED
#define LOOP0_H_INCLUDED

void
create0(double **vx, double **vy, double **vz, size_t size);

void
destroy0(double *vx, double *vy, double *vz);

double
compute0(double *vx, double *vy, double *vz, size_t size);

#endif
