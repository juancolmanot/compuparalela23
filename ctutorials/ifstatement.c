#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max(int num1, int num2, int num3){
    int result;
    
    if(num1 >= num2 && num1 >= num3) { 
        result = num1;
    }
    else if(num2 >= num1 && num2 >= num3) {
        result = num2;
    }
    else {
        result = num3;
    }

    return result;
}

int main(){
    printf("%d is bigger.\n", max(74, 10, 883));

    if(3 > 2 && 3 > 5){
        printf("True\n");
    }
    else {
        printf("False\n");
    }

    /* Negation operator */
    if(!(3 < 2)){
        printf("True\n");
    }

    return 0;
}
