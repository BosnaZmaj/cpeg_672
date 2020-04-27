//
// Created by BosnaZmaj on 4/22/2020.
//

#include <iostream>
#include <cstdlib>
using namespace std;

class InfiniteArray {
private:
    int* theData;
    int possible;
    int actual;
    
    void resize(){
        cout << "re-up from "<< possible << " to " << possible*2 << endl;
        int* newData = (int*) malloc(sizeof(int)*possible*2);
        possible = possible*2;
        for(int j = 0; j < actual; j++){
            newData[j] = theData[j];
        }
        
        free(theData);
        theData = newData;
    }
public:
    InfiniteArray(){
        theData = (int*) malloc(sizeof(int));
        possible=1;
        actual=0;
    }
    
    void add_item(int x){
        if (possible == actual){
            resize();
        }
        theData[actual] = x;
        actual++;
    }
};

int main() {
    InfiniteArray magicThing;
    for(int i = 0; i < 100; i++){
        magicThing.add_item(i*2+1);
    }
}
