#include "nbody.hxx"

/* Gravitationnal force acting on P1 due to P2.
 *
 */

#include <iostream>
using namespace std;

void
gravitationnal_force(double m1, double m2, double r1[NDIM], double r2[NDIM], 
    double softening_length_2, double force[NDIM])
{
    double G = 6.67300E-11;
    double rx,ry,rz,d2,f;

    rx = r1[0] - r2[0];
    ry = r1[1] - r2[1];
    rz = r1[2] - r2[2];

    d2 = pow(rx,2) + pow(ry,2) + pow(rz,2);

    f = - G*m1*m2 / pow(d2+softening_length_2,1.5);

    force[0] =  f * rx;
    force[1] =  f * ry;
    force[2] =  f * rz;
}

void
sum_gravitationnal_force(int nparticule, int iparticule,
    double* m, double* r, double softening_length_2, double sum_force[NDIM])
{
    int iother;
    double m_particule;
    double r_particule[NDIM], r_other[NDIM];
    double force[NDIM];

    m_particule = m[iparticule];
    r_particule[0] = r[NDIM*iparticule];
    r_particule[1] = r[NDIM*iparticule+1];
    r_particule[2] = r[NDIM*iparticule+2];

    sum_force[0] = 0.;
    sum_force[1] = 0.;
    sum_force[2] = 0.;

    for (iother=0 ; iother < nparticule ; iother++) {

        if (iother==iparticule) continue;

        r_other[0] = r[NDIM*iother];
        r_other[1] = r[NDIM*iother+1];
        r_other[2] = r[NDIM*iother+2];

        gravitationnal_force(m_particule,m[iother], 
            r_particule,r_other, softening_length_2,force);

        sum_force[0] += force[0];
        sum_force[1] += force[1];
        sum_force[2] += force[2];
    }
}
