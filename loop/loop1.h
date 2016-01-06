#ifndef LOOP1_H_INCLUDED
#define LOOP1_H_INCLUDED

typedef struct {
    double x;
    double y;
    double z;
} XYZ;

void
create1(XYZ **xyz, size_t size);

void
destroy1(XYZ *xyz);

void
compute1(XYZ *xyz, size_t size, double *x, double *time_spent);

void
setvalues1(XYZ *xyz, size_t size);

#endif
