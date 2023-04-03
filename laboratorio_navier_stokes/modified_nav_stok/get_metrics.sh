#!/bin/bash

for i in {1..10}
do
    echo "Iteration $i"

    make -s clean
    make -s OPTFLAGS="$1"
    ./headless
    ./compute_stats
done

cat ../datafiles/results.dat