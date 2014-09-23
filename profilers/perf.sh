source common.sh

g++ -O2 -fno-omit-frame-pointer -c src/main.cxx
g++ -O2 -fno-omit-frame-pointer -c src/nbody.cxx
g++ -O2 -fno-omit-frame-pointer -o profme main.o nbody.o

perf record -g ./profme $NPARTICULES $NTIMES
perf report --stdio > perf-report.txt

mv profme perf.data perf-report.txt $RESULT_DIR
rm *.o

echo
echo "See files in $RESULT_DIR/"
