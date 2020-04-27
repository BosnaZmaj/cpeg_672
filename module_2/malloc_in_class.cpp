//
// Created by BosnaZmaj on 4/22/2020.
//

#include <iostream>

#include <string>
#include <cstdlib>
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
    
    Dog* kennel = (Dog*) malloc(sizeof(Dog)*10);
    cout << "Notice: no constructors called" << endl;
    
    //this is the "placement new" constructor
    //it lets you tell C++ where to stick the new object
    new (kennel + 5) Dog("Butterscotch");
    
    (kennel + 5)->bark();
    (*(kennel + 5)).bark();
    kennel[5].bark();
    (&kennel[5])->bark();
    
    //this is optional but good practice
    kennel[5].~Dog();
    //what are the 3 other ways to call this?
    
    cout << "I ran the destructor... now to free" << endl;
    
    //when you malloc always free...
    free(kennel);
}