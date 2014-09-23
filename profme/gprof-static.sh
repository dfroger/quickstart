source common.sh

g++ -pg -c src/main.cxx
g++ -pg -c src/nbody.cxx
g++ -pg -o profme main.o nbody.o

./profme $NPARTICULES $NTIMES

gprof profme gmon.out > gprof.txt

mv profme gmon.out gprof.txt $RESULT_DIR
rm *.o
