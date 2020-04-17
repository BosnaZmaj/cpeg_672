#include "stdio.h"

int main(void){
    char text[128] = "Andy is the greatest";
    // Old fashioned c strings
    // char text[128] declares an array of 'char's and = "..." initializes the values stored in that array
    // after the "t" in greatest there will be stored a null byte (00000000) to indicate the end of the character array
    
    printf("%s\n", text);
    
    return 0;
}