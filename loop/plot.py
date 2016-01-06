from pylab import *

n,t0,t1 = loadtxt('times.txt', unpack=True)

plot(n,t0)
plot(n,t1)

fn = 'times.png'
savefig(fn)
print(fn)
