#include "stdio.h"

int compare(int a, int b){
    return a == b;
}


int main(){

    int i=0;
    for(; !compare(i,5); i++){
        printf("i=%d\n", i);
    }
    return 0;

}
