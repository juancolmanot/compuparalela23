#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    
    int age = 30;
    int *pAge = &age;

    printf("%d\n", *pAge);

    return 0;
}
