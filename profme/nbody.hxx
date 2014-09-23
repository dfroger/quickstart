#ifndef NDBODY_H_INCLUDED
#define NDBODY_H_INCLUDED

#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>

#define G 6.67300E-11

class Particule
{
    public:
        Particule(double mass, double x, double y, double z, size_t idx);

        inline size_t idx() const { return m_idx; }

        inline double x() const { return m_x; }
        inline double y() const { return m_y; }
        inline double z() const { return m_z; }
        inline double mass() const { return m_mass; }

        inline double& fx() { return m_fx; }
        inline double& fy() { return m_fy; }
        inline double& fz() { return m_fz; }

        void update_position(double delta_t);
    private:
        size_t m_idx;
        double m_mass;
        double m_x, m_y, m_z;
        double m_fx, m_fy, m_fz;
};

void
init_particules(size_t n, std::vector<Particule>& particules);

void
save_positions(std::vector<Particule>& particules, size_t itime);

void
gravitationnal_force(Particule other, Particule& part, double sl2);

void
sum_gravitationnal_force(std::vector<Particule>& particules,
                         Particule& particule, double sl2);
void
time_step(std::vector<Particule>& particules, double delta_t, double sl2);

#endif
