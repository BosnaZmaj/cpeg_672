//
// Created by BosnaZmaj on 4/22/2020.
//
#include <iostream>
#include <string>
using namespace std;

//Define the interface for a Dog-type
class Dog {
private:
    string name; //name is private, the outside world can't access
public:
    // this is the "constructor" which
    // gets executed upon instantiation
    Dog(string starter_name){
        name = starter_name;
    }
    //these are public "methods"
    void read_tag(); //this one will get defined later
    void rename(string new_name){ name = new_name; } //def. here
};

//When defining later I need to include the "scope"
void Dog::read_tag(){
    cout << "This dog is named " << name << endl;
}


int main() {
    //Creating a new pet from the Dog class
    //pay little attention to the dereferencer
    Dog *p2dog = new Dog("Fido");
    Dog my_pet = *(p2dog);
    
    //when working with an object you can use "dot notation"
    //to call a method (like buttons on a microwave)
    my_pet.read_tag();
    my_pet.rename("Spot");
    my_pet.read_tag();
    
    //this next line would give an error:
    //cout << my_pet.name << endl;
    //main.cpp:7:12: error: 'std::string Dog::name' is private
    
    delete p2dog;
    
}

