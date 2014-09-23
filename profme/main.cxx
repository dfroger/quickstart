#include "nbody.hxx"
#include "stdio.h"

int main()
{
    double m1 = 1.E+05;
    double m2 = 1.E+09;
    double r1[3] = {10., 20., 30.};
    double r2[3] = {60., 50., 40.};
    double softening_length_2 = 1;
    double force[3] = {0., 0., 0.};

    gravitationnal_force(m1,m2,r1,r2,softening_length_2,force);

    printf("%g\n", force[0]);
    printf("%g\n", force[1]);
    printf("%g\n", force[2]);

    return 0;
}
