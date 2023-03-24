#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{   
    /* Known array */
    int luckyNumbers1[] = {4, 8, 15, 16, 23, 42};
    luckyNumbers1[1] = 200;
    printf("%d\n", luckyNumbers1[1]);

    /* Known size of array */
    int luckyNumbers2[10];
    luckyNumbers2[1] = 80;
    printf("%d\n", luckyNumbers2[0]);

    /* Array of characters*/
    char phrase[20] = "Array";
    printf("%s\n", phrase);


    

    return 0;
}