#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{   
    int age;
    double gpa;
    char grade;
    char name[20];
    printf("Enter your age: \n");
    scanf("%d", &age);
    printf("Enter your gpa: \n");
    scanf("%lf", &gpa);
    printf("You are %d years old\n", age);
    printf("Your gpa is %f\n", gpa);
    printf("Enter your name: \n");
    scanf("%s", name);
    printf("Your name is %s \n", name);

    fgets(name, 20, stdin);
    printf("Your name is %s", name);

    return 0;
}