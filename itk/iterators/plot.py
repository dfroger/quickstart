#!/usr/bin/env python
import matplotlib
matplotlib.use('Agg')
from pylab import *

c_pointer_size = []
c_pointer_seconds = []

itk_iterators_size = []
itk_iterators_seconds = []

with open('times.txt') as f:
    for line in f.readlines():
        method, ny, nx, seconds = line.split()
        ny = int(ny)
        nx = int(nx)
        seconds = float(seconds)
        if method == 'c_pointer':
            c_pointer_size.append(nx*ny)
            c_pointer_seconds.append(seconds)
        elif method == 'itk_iterator':
            itk_iterators_size.append(nx*ny)
            itk_iterators_seconds.append(seconds)
        else:
            raise ValueError, "No such method: %r" % method

assert c_pointer_size == itk_iterators_size

plot(c_pointer_size, c_pointer_seconds, 'ro-', label='C pointers')
plot(itk_iterators_size, itk_iterators_seconds, 'bo-', label='ITK iterators')
xlabel('Image size')
ylabel('Execution time (seconds)')
legend()
savefig('times.png')
