#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    int index = 1;
    /* regular while loop */
    while(index <= 5) {
        printf("%d\n", index);
        index++;
    }

    /* do while loop, it enters first to the loop */
    /* then it checks the condition*/

    do {
        printf("%d\n", index);
        index++;
    } while(index <= 5);

    return 0;
}
