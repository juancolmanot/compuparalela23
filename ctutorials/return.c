#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Function defined before main method. */
double cube(double num){
    double result = num * num * num;
    return result;
}

int main(){
    printf("Answer: %f \n", cube(7.0));

    return 0;
}


