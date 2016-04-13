#include <stdio.h>
#include <stdlib.h>

#include "tool.h"

#include "mpi.h"

int
main( int argc, char **argv )
{
    // Parse command line.
    if (argc != 3) {
        fprintf(stderr, "Usage: ./read_mpi_io DATA_SIZE CHECK_VALUE\n");
        exit(1);
    }
    size_t data_size = atoi(argv[1]);
    data_size = data_size * data_size;
    size_t check_values = atoi(argv[2]);

    // Initialize MPI.
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Compute partition index.
    size_t i0, i1;
    compute_partition_index(size, rank, data_size, &i0, &i1);

    // Allocate data partition.
    size_t partition_size = i1 - i0;
    double* partition = malloc((partition_size+1)*sizeof(double));

    double start_time = get_wall_time();

    // Open file
    MPI_File f;
    MPI_File_open(MPI_COMM_WORLD, "data.bin", MPI_MODE_RDONLY, MPI_INFO_NULL, &f);

    // Otherwise MPI_Barrier has no effect.
    if (check_values) MPI_File_set_atomicity(f, 1);

    // Seek to partition first index.
    MPI_File_set_view(f, i0*sizeof(double), MPI_DOUBLE, MPI_DOUBLE,
                      "native", MPI_INFO_NULL);

    // Read partition from file.
    MPI_Status status;
    MPI_File_read(f, partition, partition_size, MPI_DOUBLE, &status);

    if (check_values) check_data_mean(partition, partition_size, data_size);

    // Close file.
    MPI_File_close(&f);

    double end_time = get_wall_time();

    // Finalize MPI.
    MPI_Finalize();

    free(partition);

    printf("%d %.7f\n", rank, end_time-start_time);

    return 0;
}
