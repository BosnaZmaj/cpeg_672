//
// Created by BosnaZmaj on 4/20/2020.
//

#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

int main() {
    int p2stack[5];
    int *p2heap = (int *)malloc(sizeof(int)*5);
    
    cout << p2stack << endl;
    cout << p2heap << endl;
    
    free(p2heap);
}