//
// Created by BosnaZmaj on 4/20/2020.
//

#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

int main() {
    int array_of_ints[5];
    
    for(int i = 0; i < 5; i++){
        array_of_ints[i] = i*i;
        cout << "value at "
             << i
             << " is: "
             << array_of_ints[i]
             << endl;
    }
    
    for(int i = 0; i < 5; i++){
        cout << "address of array_of_ints["
             << i
             << "] is: "
             << &array_of_ints[i]
             << endl;
    }
    
    cout << "value of plain array_of_ints: "<< array_of_ints << endl;
    for (int i = 1; i < 5; i++){
        cout << "value of crazy pointer arith.: " << array_of_ints + i << endl;
    }
    
    for (int i = 0; i < 5; i++){
        cout << "crazy pointer dereference: " << *(array_of_ints + i) << endl;
    }
}
