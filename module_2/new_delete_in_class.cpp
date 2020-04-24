//
// Created by BosnaZmaj on 4/22/2020.
//

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Dog {
    int num_legs;
public:
    Dog(){ num_legs = 4; cout << "Hi there" << endl;}
    ~Dog(){ cout << "Thanks for the life... I'm out" << endl; };
};

int main() {
    Dog* kennel = new Dog[10];
    delete[] kennel;
}