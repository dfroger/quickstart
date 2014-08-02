#!/usr/bin/env python

import os
from distutils.core import setup, Extension

import mpi4py

mpi4py_inc = mpi4py.get_include()

mpi_bin_dir = os.path.dirname( mpi4py.get_config()['mpicc'] )
mpi_dir = os.path.realpath( os.path.join(mpi_bin_dir,'..') )
mpi_inc_dir = os.path.join(mpi_dir, 'include')
mpi_lib_dir = os.path.join(mpi_dir, 'lib')

compute_pi = Extension('_compute_pi',
   sources = ['compute_pi.i', 'compute_pi.c'],
   libraries = ['mpich','opa','mpl','rt','pthread'],
   include_dirs = [mpi_inc, mpi4py_inc],
   library_dirs = [mpi_lib_dir],
   runtime_library_dirs = [mpi_lib_dir],
   swig_opts=['-I' + mpi4py_inc],
   )

setup (name = 'compute_pi',
       version = '0.1',
       ext_modules = [compute_pi],
       py_modules = ["compute_pi"],
       )
