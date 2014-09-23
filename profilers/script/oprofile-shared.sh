source $(dirname $0)/common.sh

g++ -O2 -fno-omit-frame-pointer -c -fPIC $NBODY_CXX
g++ -shared -o libnbody.so nbody.o
g++ -O2 -fno-omit-frame-pointer -c -fPIC $MAIN_CXX
g++ -O2 -fno-omit-frame-pointer -o profme main.o -L$PWD -Wl,-R,$PWD libnbody.so

operf ./profme $NPARTICULES $NTIMES

opgprof
gprof profme gmon.out > gprof-compatible.txt
