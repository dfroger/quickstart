source common.sh

g++ -O2 -c src/main.cxx
g++ -O2 -c src/nbody.cxx
g++ -O2 -o profme main.o nbody.o

valgrind --tool=callgrind ./profme $NPARTICULES $NTIMES

callgrind_annotate

mv profme callgrind.out.* callgrind.txt $RESULT_DIR
rm *.o

echo
echo "See files in $RESULT_DIR/"
