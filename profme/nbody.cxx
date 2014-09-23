#include "nbody.hxx"

#include <sstream>
#include <fstream>

using namespace std;

double drand()
{
    return (double)rand() / RAND_MAX;
}

void
init_particules(size_t n, vector<Particule>& particules)
{
    double mass,x,y,z;

    particules.clear();

    for (size_t i = 0 ; i < n ; ++i) {
        mass = drand();
        x = drand();
        y = drand();
        z = drand();
        Particule p(mass, x, y, z, i);
        particules.push_back(p);
    }
}

void
save_positions(vector<Particule>& particules, size_t itime)
{
    ostringstream filename;
    filename << "pos" << itime << ".txt";

    ofstream f;
    f.open(filename.str().c_str());
    for (vector<Particule>::iterator 
            it  = particules.begin() ;
            it != particules.end() ;
            it++)
    {
        f << it->x() << " "
          << it->y() << " "
          << it->z() << endl;
    }
    f.close();
}

Particule::Particule(double mass, double x, double y, double z, size_t idx):
    m_idx(idx),
    m_mass(mass),
    m_x(x),
    m_y(y),
    m_z(z),
    m_fx(0.),
    m_fy(0.),
    m_fz(0.)
{
}

void
Particule::update_position(double delta_t)
{
    m_x += delta_t * m_fx / m_mass;
    m_y += delta_t * m_fy / m_mass;
    m_z += delta_t * m_fz / m_mass;
}

/* Gravitationnal force acting on part due to other.  */
void
gravitationnal_force(Particule other, Particule& part, double sl2)
{
    double rx = part.x() - other.x();
    double ry = part.y() - other.y();
    double rz = part.z() - other.z();

    double d2 = pow(rx,2) + pow(ry,2) + pow(rz,2);

    double f = - G * part.mass() * other.mass()
                   / pow(d2 + sl2, 1.5);

    part.fx() += f * rx;
    part.fy() += f * ry;
    part.fz() += f * rz;
}

void
sum_gravitationnal_force(vector<Particule>& particules,
                         Particule& particule, double sl2)
{
    particule.fx() = 0.;
    particule.fy() = 0.;
    particule.fz() = 0.;

    for (vector<Particule>::iterator 
            other_it  = particules.begin() ;
            other_it != particules.end() ;
            other_it++)
    {
        if (other_it->idx() == particule.idx()) continue;

        gravitationnal_force(*other_it, particule, sl2);
    }
}

void
time_step(vector<Particule>& particules, double delta_t, double sl2)
{
    for (vector<Particule>::iterator 
            it  = particules.begin() ;
            it != particules.end() ;
            it++)
    {
        sum_gravitationnal_force(particules, *it, sl2);
        it->update_position(delta_t);
    }
}
