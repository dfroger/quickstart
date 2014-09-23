#include <iostream>
#include <algorithm>

#include "nbody.hxx"

using namespace std;

int main(int argc, char** argv)
{
    if (argc != 3) {
        cerr << "Usage: ./profme NPARTICULES NTIMES" << endl;
        exit(1);
    }

    size_t nparticules = atoi(argv[1]);
    size_t ntimes = atoi(argv[2]);
    double delta_t = 1.E+6;
    double softening_length_2 = 0.01;

    vector<Particule> particules;
    init_particules(nparticules, particules);

    size_t onepct = std::max(ntimes / 100, (size_t)1);
    for (size_t itime = 0 ; itime < ntimes ; itime++) {
        time_step(particules, delta_t, softening_length_2);
        if (itime % onepct == 0) {
            cout << itime / onepct  << " %" << endl;
            //save_positions(particules, itime);
        }
    }

    return 0;
}
