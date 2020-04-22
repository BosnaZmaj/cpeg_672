//
// Created by BosnaZmaj on 4/22/2020.
//

#include <iostream>
#include <string>
using namespace std;

class Dog {
    string name;
public:
    Dog(string new_name){
        name = new_name;
        cout << "Hooray for existence!" << endl;
    }
    //this is the "destructor"
    ~Dog(){
        cout << "I'm melting..." << endl;
    }
    void bark(){
        cout << "Woof, love " << name << endl;
    };
};

int main() {
    Dog puppy("Bob");
    puppy.bark();
}
