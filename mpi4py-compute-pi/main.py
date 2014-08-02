#!/usr/bin/env python
from mpi4py import MPI
from compute_pi import compute_pi

comm = MPI.COMM_WORLD
size = comm.Get_size()
rank = comm.Get_rank()

mypi = compute_pi(rank, size, 100, comm)
print mypi

