#!/bin/bash

NITER=1000
VERBOSE=0

rm -f times.txt

for N in $(seq 100 100 1000)
do
    echo $N
    ./iterators $N $N $NITER $VERBOSE >> times.txt
done
