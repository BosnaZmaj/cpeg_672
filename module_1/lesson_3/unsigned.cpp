//
// Created by BosnaZmaj on 4/20/2020.
//

#include<iostream>
#include<bitset>
using namespace std;

int main(){
    char signed_banana = 129;
    char pseudo_signed_banana = -127;
    unsigned char unsigned_banana = 129;
    cout << "Banana bits: " << bitset<8>(signed_banana) << endl;
    cout << "iBanana bits: " << bitset<8>(unsigned_banana) << endl;
    
    if (signed_banana == pseudo_signed_banana){
        cout << "Uh-oh the signed_banana is negative? ";
    } else {
        cout << "The signed_banana was OK. phew!";
    }
    
    cout << int(signed_banana) << endl;
    
    if (unsigned_banana == pseudo_signed_banana){
        cout << "Uh-oh the unsigned_banana is negative? ";
    } else {
        cout << "The unsigned banana was OK. phew!";
    }
    cout << int(unsigned_banana) << endl;
    
    cout << endl << "Aside, when printing a char as a number I had to cast it: ";
    cout << signed_banana << endl;
    
    return 0;
};
