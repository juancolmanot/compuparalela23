#!/bin/bash

for i in {1..3}
do
    echo "Iteration $i"

    make -s clean
    make -s OPTFLAGS="$1"
    ./headless
    ./compute_stats $i 0 32
done
echo "Finish Fluid Simulation"




