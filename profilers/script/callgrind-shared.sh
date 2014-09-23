source $(dirname $0)/common.sh

g++ -O2 -c -fPIC $NBODY_CXX
g++ -shared -o libnbody.so nbody.o
g++ -O2 -c -fPIC $MAIN_CXX
g++ -O2 -o profme main.o -L$PWD -Wl,-R,$PWD libnbody.so

valgrind --tool=callgrind ./profme $NPARTICULES $NTIMES
