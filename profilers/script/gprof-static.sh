source $(dirname $0)/common.sh

g++ -O2 -pg -c src/main.cxx
g++ -O2 -pg -c src/nbody.cxx
g++ -O2 -pg -o profme main.o nbody.o

./profme $NPARTICULES $NTIMES

gprof profme gmon.out > gprof.txt

mv profme gmon.out gprof.txt $RESULT_DIR
rm *.o

echo
echo "See files in $RESULT_DIR/"
