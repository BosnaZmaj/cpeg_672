//
// Created by BosnaZmaj on 4/23/2020.
//

#include <iostream>
using namespace std;

class DebitCard {
protected:
    int pin[4];
public:
    DebitCard(const int* input){
        for(int i = 0; i < 4; i++){
            pin[i] = input[i];
        }
    };
    int& operator[](int i){
        return pin[i];
    };
};

int main() {
    int mypin[4] = {5,6,7,8};
    DebitCard visa(mypin);
    cout << visa[2] << endl;
    visa[2] = 1;
    cout << visa[2] << endl;
}