//
// Created by BosnaZmaj on 4/20/2020.
//


#include <iostream>
using namespace std;

void double_pass_by_value(int a){
    a *= 2;
}

void double_pass_by_reference(int &r){
    r *= 2;
}

int main() {
    
    int x = 10;
    
    cout << "x: " << x << endl;
    
    double_pass_by_value(x);
    cout << "x after pbv:" << x << endl;
    
    double_pass_by_reference(x);
    cout << "x after pbr:" << x << endl;
    
}
