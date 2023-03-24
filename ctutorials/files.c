#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    
    /* write to file */
    FILE * fpointer1 = fopen("test.txt", "a");

    fprintf(fpointer1, "\nMauro, Ingeniero");

    fclose(fpointer1);

    /* read from file */

    char line[255];
    FILE * fpointer2 = fopen("test.txt", "r");

    int i;
    for(i=0; i < 4; i++){
        fgets(line, 255, fpointer2);
        printf("%s\n", line);

    }
    
    return 0;
}
