source $(dirname $0)/common.sh

g++ -O2 -fno-omit-frame-pointer -c src/main.cxx
g++ -O2 -fno-omit-frame-pointer -c src/nbody.cxx
g++ -O2 -fno-omit-frame-pointer -o profme main.o nbody.o

opgprof ./profme $NPARTICULES $NTIMES

echo
echo "See files in $RESULT_DIR/"
