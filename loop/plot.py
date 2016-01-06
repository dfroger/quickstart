from pylab import *

n,t0,t1 = loadtxt('times.txt', unpack=True)

plot(n,t0, label='version 0')
plot(n,t1, label='version 1')
legend()

fn = 'times.png'
savefig(fn)
print(fn)
