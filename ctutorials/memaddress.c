#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    
    int age = 30;
    double gpa = 3.4;
    char grade = 'A';

    printf("age: %X\ngpa: %X\ngrade: %X\n", &age, &gpa, &grade);

    return 0;
}
