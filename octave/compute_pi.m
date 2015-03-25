function[mypi] = compute_pi(mpi_rank, mpi_size, n)
% document here

    h = 1.0 / n;
    sum = 0.;

    for (i = mpi_rank + 1 : mpi_size : n)
        x = h * (i - 0.5);
        sum = sum + (4.0 / (1.0 + x*x)); 
    end

    mypi = h * sum;
end

mpi_rank = 0;
mpi_size = 1;
n = 200;

compute_pi(mpi_rank, mpi_size, n)
