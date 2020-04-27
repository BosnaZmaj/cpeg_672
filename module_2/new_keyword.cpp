//
// Created by BosnaZmaj on 4/22/2020.
//

#include <iostream>
#include <string>
using namespace std;

class Dog {
    //private by default
    string name;
public:
    Dog(string starter_name){
        name = starter_name;
    }
    void taunt(){ bark(); };
    void read_tag();
protected:
    void bark();
};

void Dog::bark(){
    cout << "Grrr Woof" << endl;
};

void Dog::read_tag(){
    cout << "This dog is named " << name << endl;
}

int main() {
    //This the way many people work with objects
    Dog* p2fido = new Dog("Fido");
    //to use dot notation you have to dereference
    (*p2fido).read_tag();
    //but C++ provides a dereference + dot symbol
    p2fido->taunt();
    
    //The arrow consumes an address, dereferences and accesses the method or attribute
    //So to work directly with an object:
    Dog fido = *p2fido;
    //use the dot notation
    fido.read_tag();
    
    // but if you're feeling nutty:
    // address and arrow is the same
    (&fido)->taunt();
    
    //delete needs to work on a pointer
    delete p2fido;
}

