n = 200;
h = 1.0 / n;
printf('%d\n', n);
printf('%g\n', h);

mpi_rank = 0;
mpi_size = 1;

sum = 0.;

for (i = mpi_rank + 1 : mpi_size : n)
    x = h * (i - 0.5);
    sum = sum + (4.0 / (1.0 + x*x)); 
end

result = h * sum

printf('%15.10g\n', result);
