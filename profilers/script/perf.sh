source $(dirname $0)/common.sh

g++ -O2 -fno-omit-frame-pointer -c $MAIN_CXX
g++ -O2 -fno-omit-frame-pointer -c $NBODY_CXX
g++ -O2 -fno-omit-frame-pointer -o profme main.o nbody.o

perf record -g ./profme $NPARTICULES $NTIMES
perf report --stdio > perf-report.txt
