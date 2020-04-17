#include "stdio.h"

int main(){
    int i;

    // The first part of this for loop is run once as an initialization
    // The second part is checked for truth at the end of each execution to determine if the loop should be run again
    // the third part is executed at the end of the loop (typically used to increment something)

    for (i = 0; i < 5; i++){
        printf("i = %d\n", i);
    }
    return 0;
}
