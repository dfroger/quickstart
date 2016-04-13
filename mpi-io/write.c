#include <stdio.h>
#include <stdlib.h>

#include "tool.h"

#include "mpi.h"

int
main( int argc, char **argv )
{
    // Parse command line.
    if (argc != 2) {
        fprintf(stderr, "Usage: ./write_mpi_io DATA_SIZE\n");
        exit(1);
    }
    size_t data_size = atoi(argv[1]);
    data_size = data_size * data_size;

    // Initialize MPI.
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
    MPI_Comm_size( MPI_COMM_WORLD, &size );

    // Compute partition index.
    size_t i0, i1;
    compute_partition_index(size, rank, data_size, &i0, &i1);

    // Allocate data partition.
    size_t partition_size = i1 - i0;
    double* partition = (double*) malloc(partition_size*sizeof(double));

    // Set data partition values.
    size_t i;
    for (i = 0 ; i < partition_size ; i++)
        partition[i] = i0 + i;

    double start_time = get_wall_time();

    // Open file
    MPI_File f;
    int mode = MPI_MODE_CREATE | MPI_MODE_WRONLY;
    char filename[] = "data.bin";
    MPI_File_open(MPI_COMM_WORLD, filename, mode, MPI_INFO_NULL, &f);

    // Seek to partition first index.
    MPI_File_set_view(f, i0*sizeof(double), MPI_DOUBLE, MPI_DOUBLE,
                      "native", MPI_INFO_NULL);

    // Write partition to file.
    MPI_Status status;
    MPI_File_write(f, partition, partition_size, MPI_DOUBLE, &status);

    // Close file.
    MPI_File_close(&f);

    double end_time = get_wall_time();

    // Finalize MPI.
    MPI_Finalize();

    printf("%d %.7f\n", rank, end_time-start_time);

    return 0;
}
