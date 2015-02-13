#!/usr/bin/env python
import matplotlib
matplotlib.use('Agg')
from pylab import *

c_pointer_size = []
c_pointer_seconds = []

itk_iterators_size = []
itk_iterators_seconds = []

itk_convolution_size = []
itk_convolution_seconds = []

itk_buffer_size = []
itk_buffer_seconds = []

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
        elif method == 'itk_convolution':
            itk_convolution_size.append(nx*ny)
            itk_convolution_seconds.append(seconds)
        elif method == 'itk_get_buffer_pointer':
            itk_buffer_size.append(nx*ny)
            itk_buffer_seconds.append(seconds)
        else:
            raise ValueError, "No such method: %r" % method

plot(c_pointer_size, c_pointer_seconds, 'ro-', label='C pointers')
#plot(itk_iterators_size, itk_iterators_seconds, 'bo-', label='ITK iterators')
#plot(itk_convolution_size, itk_convolution_seconds, 'go-', label='ITK convolution')
plot(itk_buffer_size, itk_buffer_seconds, 'ko-', label='ITK get buffer pointer')

xlabel('Image size')
ylabel('Execution time (seconds)')
legend()
savefig('times.png')
