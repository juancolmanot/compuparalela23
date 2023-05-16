#!/bin/bash

ordered_output(){
    echo "size ns_base	ns_cell	react	vel_step	dens_step	L1-l-base	L1-m-base	L1-loads	L1-misses" > $1.dat
    size=$(grep 'N = ' headless.c | head -n 1 | awk '{print $3}' | tr -d ';')
    cells=$(grep 'media' $1 | awk '{print $4}' | sed 's/,$//' | sed 's/,/./' | pr -t --columns=4)
    echo "$size $cells" >> $1.dat

}

ordered_output $1