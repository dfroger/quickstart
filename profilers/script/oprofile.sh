source $(dirname $0)/common.sh

g++ -O2 -fno-omit-frame-pointer -c src/main.cxx
g++ -O2 -fno-omit-frame-pointer -c src/nbody.cxx
g++ -O2 -fno-omit-frame-pointer -o profme main.o nbody.o

operf ./profme $NPARTICULES $NTIMES

opreport > oprofile.txt

mv oprofile_data oprofile.txt $RESULT_DIR

echo
echo "See files in $RESULT_DIR/"
