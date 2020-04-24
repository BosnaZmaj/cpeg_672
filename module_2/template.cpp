//
// Created by BosnaZmaj on 4/22/2020.
//
#include <iostream>

template<typename T>
T add_two(T a, T b){
    return a + b;
}

int main() {
    std::cout << add_two<int>(12, 34) << std::endl;
    std::cout << add_two<float>(12.3, 34.3) << std::endl;
}
