default: help

help:
	@echo "Use one of the following target:"
	@echo "main    build C++ main program"
	@echo "ext     build Python extension module"
	@echo "test    test Python module with 4 procs"

%.o: %.c
	mpicc -g -c $<

main: main.o compute_pi.o
	mpicc -g -o $@ $^

ext: compute_pi.h compute_pi.c compute_pi.i setup.py
	python setup.py build_ext --inplace

clean:
	@rm -rf build/ main *.o compute_pi_wrap.c compute_pi.py \
			_compute_pi.so *.pyc

notebook:
	ipython notebook --browser=firefox

ipcluster:
	ipcluster start -n 6 --profile='mpi'

test:
	mpiexec -n 4 python main.py
