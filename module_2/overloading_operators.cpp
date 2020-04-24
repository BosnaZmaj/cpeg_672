//
// Created by BosnaZmaj on 4/23/2020.
//

#include <iostream>
using namespace std;

class Fruit {
protected:
    int ripeness;
public:
    Fruit(){
        ripeness = 10;
    }
    friend ostream& operator<<(ostream& os, const Fruit& fruit){
        os << fruit.ripeness;
        return os;
    }
};

int main() {
    Fruit banana;
    cout << banana << endl;
}