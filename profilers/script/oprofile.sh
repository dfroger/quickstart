source $(dirname $0)/common.sh

g++ -O2 -fno-omit-frame-pointer -c $MAIN_CXX
g++ -O2 -fno-omit-frame-pointer -c $NBODY_CXX
g++ -O2 -fno-omit-frame-pointer -o profme main.o nbody.o

operf ./profme $NPARTICULES $NTIMES

opreport > oprofile.txt
opgprof
gprof profme gmon.out > gprof-compatible.txt
