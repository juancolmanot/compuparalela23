#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    
    /*int i = 1;
    while(i <= 5){
        printf("%d\n", i);
        i++;
    }*/

    int luckyNumbers [] = {4, 8, 15, 16, 23, 42};

    int i;
    for(i = 0; i < 6; i++){
        printf("%d\n", luckyNumbers[i]);
    }

    return 0;
}
