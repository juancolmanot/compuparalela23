#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* function == method (kind of...) */


/* main() always gets called */
int main()
{
    printf("Top\n");
    sayHi("Juan",27);
    sayHi("Braian",27);
    sayHi("Pome",27);
    printf("Bottom\n");
    return 0;
}

void sayHi(char name[], int age){
    printf("Hello %s, you are %d.\n", name, age);

}
