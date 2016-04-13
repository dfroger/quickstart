#include <stdio.h>
#include <sys/time.h>
#include <math.h>

#include "mpi.h"

#include "tool.h"

void
compute_partition_index(int mpi_size, int mpi_rank,
                        size_t data_size, size_t* i0, size_t* i1)
{
    *i0 = data_size *  mpi_rank / mpi_size;
    *i1 = data_size * (mpi_rank+1) / mpi_size;
}

// Copy-paste from http://stackoverflow.com/a/17440673
double
get_wall_time()
{
    struct timeval time;
    if (gettimeofday(&time,NULL)){
        fprintf(stderr, "ERROR: get_wall_time failed");
        return 0;
    }
    return (double)time.tv_sec + (double)time.tv_usec * .000001;
}

double
compute_data_mean_expected(size_t data_size)
{
    return 0.5*((double)data_size-1);
}

void
check_data_mean(double* partition, size_t partition_size, size_t data_size)
{
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Compute partition mean.
    double partition_mean = 0.;
    size_t i;
    for (i = 0 ; i < partition_size ; i++) {
        partition_mean += partition[i];
    }
    partition_mean /= partition_size;

    // Make sure all processes have compute their partition_mean.
    MPI_Barrier(MPI_COMM_WORLD);

    // Each partition send its mean.
    double data_mean = 0.;
    int master_rank = 0;
    MPI_Reduce(&partition_mean, &data_mean, 1, MPI_DOUBLE, MPI_SUM,
               master_rank, MPI_COMM_WORLD);

    // Only master rank check data mean.
    if (rank != master_rank) 
        return;

    data_mean /= size;

    double expected = compute_data_mean_expected(data_size);

    if (fabs(data_mean-expected) > 1.E-07) {
        fprintf(stderr,
                "ERROR: For size %d, expected data mean to be: %.9f, but got: %.9f\n",
                size, expected, data_mean);
    } else {
        fprintf(stderr,
                "OK: For size %d, data mean %.2f matches expected value %.2f\n",
                 size, data_mean, expected);
    }
}
