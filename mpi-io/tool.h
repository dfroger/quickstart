#ifndef TOOL_H_INCLUDED
#define TOOL_H_INCLUDED

void
compute_partition_index(int mpi_size, int mpi_rank,
                        size_t data_size, size_t* i0, size_t* i1);

double
get_wall_time();

double
compute_data_mean_expected(size_t data_size);

void
check_data_mean(double* partiton, size_t partition_size, size_t data_size);

#endif
