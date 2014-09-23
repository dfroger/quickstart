from glob import glob
from os.path import splitext
from pylab import *

fig = figure()
for filename in sorted( glob('pos*.txt') ):
    basename = splitext(filename)[0]
    x,y,z = loadtxt(filename, unpack=True)

    fig.clf()
    plot(x,y,'bo')
    axis('scaled')
    #xlim(0,1)
    #ylim(0,1)
    imagename = basename+'.png'
    savefig(imagename)
    print imagename
