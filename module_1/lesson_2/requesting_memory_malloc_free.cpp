//
// Created by BosnaZmaj on 4/20/2020.
//

#include <iostream>
#include<cstdlib>
#include<bitset>
using std::cout;
using std::endl;

int main() {
    bool *ptr_to_chunk;
    ptr_to_chunk = (bool *) malloc(sizeof(bool)*200);
    ptr_to_chunk[0] = true;
    ptr_to_chunk[199] = false;
    cout << ptr_to_chunk[0] << endl;
    free(ptr_to_chunk);
}

