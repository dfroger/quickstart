source $(dirname $0)/common.sh

g++ -O2 -pg -c $MAIN_CXX
g++ -O2 -pg -c $NBODY_CXX
g++ -O2 -pg -o profme main.o nbody.o

./profme $NPARTICULES $NTIMES

gprof profme gmon.out > gprof.txt
