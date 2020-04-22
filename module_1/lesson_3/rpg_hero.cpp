//
// Created by BosnaZmaj on 4/22/2020.
//
#include<iostream>
#include<bitset>
using namespace std;

bool is_female(unsigned char the_hero){
    if ((the_hero >> 7) & 0b1 == 1){
        return true;
    }
    return false;
}

string get_weapon(unsigned char the_hero){
    unsigned char weapon_value = (the_hero >> 5) & 3;
    string the_weapon;
    switch (weapon_value){
        case 0:
            the_weapon = "Axe";
            break;
        case 1:
            the_weapon = "Sword";
            break;
        case 2:
            the_weapon = "Wand";
            break;
        case 3:
            the_weapon = "Bow";
            break;
        default:
            the_weapon = "smile";
            break;
    }
    return the_weapon;
}

int main(){
    
    unsigned char the_hero = 0b11110011;
    
    if (is_female(the_hero)){
        cout << "This hero is female!  RAWR." << endl;
    } else {
        cout << "This hero is male.  OOH." << endl;
    }
    
    cout << "The hero is carrying a " << get_weapon(the_hero) << endl;
    
    return 0;
};
