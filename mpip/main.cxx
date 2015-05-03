//#include <stdlib.h>
#include <unistd.h>

#include <mpi.h>

using namespace std;

int main(int argc, char* argv[]) {
    int sleeptime = 10;
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Barrier(MPI_COMM_WORLD);
    if (rank == 0) {
        /* slacker! delaying everyone else */
        sleep(sleeptime);
      }
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();

    return 0;
}
