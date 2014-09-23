source $(dirname $0)/common.sh

g++ -O2 -c $MAIN_CXX
g++ -O2 -c $NBODY_CXX
g++ -O2 -o profme main.o nbody.o

valgrind --tool=callgrind ./profme $NPARTICULES $NTIMES

callgrind_annotate --tree=both > callgrind.txt
