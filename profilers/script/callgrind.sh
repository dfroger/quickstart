source $(dirname $0)/common.sh

g++ -O2 -c src/main.cxx
g++ -O2 -c src/nbody.cxx
g++ -O2 -o profme main.o nbody.o

valgrind --tool=callgrind ./profme $NPARTICULES $NTIMES

callgrind_annotate --tree=both > callgrind.txt

mv profme callgrind.out.* callgrind.txt $RESULT_DIR
rm *.o

echo
echo "See files in $RESULT_DIR/"
echo "Run: kcachegrind $RESULT_DIR/callgrind.out.*"
echo "Note: Don't know how to generate in ascii files same information as kcachedgrind"
