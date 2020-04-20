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
    
    cout << "ptr_to_chunk: " << ptr_to_chunk << endl;
    cout << "&prt_to_chunk[1]: " << ptr_to_chunk + 1 << endl;
    cout << "ptr_to_chunk[0]: " << *ptr_to_chunk << endl;
    cout << "ptr_to_chunk[1]: " << *(ptr_to_chunk+1) << endl;
    cout << std::bitset<32>(*(int *)ptr_to_chunk) << endl;
    
    *ptr_to_chunk = 1;
    char &c = *(char *)ptr_to_chunk;
    c = 'A';
    
    *(ptr_to_chunk + 1) = 1;
    char &d = *(char *)(ptr_to_chunk + 2);
    d = 'n';
    
    cout << "ptr_to_chunk: " << ptr_to_chunk << endl;
    cout << "&prt_to_chunk[1]: " << ptr_to_chunk + 1 << endl;
    cout << "ptr_to_chunk[0]: " << *ptr_to_chunk << endl;
    cout << "ptr_to_chunk[1]: " << *(ptr_to_chunk+1) << endl;
    cout << std::bitset<32>(*(int *)ptr_to_chunk) << endl;
    
    free(ptr_to_chunk);
}
