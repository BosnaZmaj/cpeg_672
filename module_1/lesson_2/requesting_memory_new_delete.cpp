//
// Created by BosnaZmaj on 4/20/2020.
//

#include <iostream>
using namespace std;

string* create_beatle(int index){
    string beatles[4] =
            {"John", "Paul", "George", "Ringo"};
    string* newBeatleAddr = new string;
    *newBeatleAddr = beatles[index];
    return newBeatleAddr;
}

int main() {
    
    int index = 0;
    string* beatleHomes[4];
    
    for(; index < 4; index++){
        beatleHomes[index] = create_beatle(index);
    }
    
    for (int i = 0; i < 4; i++){
        cout << beatleHomes[i]
             << " houses "
             << *beatleHomes[i]
             << endl;
        
        delete beatleHomes[i];
        cout << "evicted" << endl;
    }
}