%module compute_pi

%{
#include "compute_pi.h"
%}

%include "mpi4py/mpi4py.i"
%mpi4py_typemap(Comm, MPI_Comm);
%include "compute_pi.h"
