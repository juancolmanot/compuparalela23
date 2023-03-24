#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/* Function defined under main method. */

/* This is called prototype the function. */

double cube(double num); /* Function signature.*/

int main(){
    printf("Answer: %f \n", cube(7.0));

    return 0;
}


double cube(double num){
    return num * num * num;
}
