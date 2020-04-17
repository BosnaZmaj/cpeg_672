//
// Created by BosnaZmaj on 4/16/2020.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(){
    
    // String to hold the file
    string encoded_text;
    
    // Read from the text file
    ifstream encoded_file("input");
    
    // Use a while loop together with the getline() function to read the file line by line
    while (getline (encoded_file, encoded_text)){
        // Output the text from the file
        
        cout << encoded_text << endl;
        
    }
    // Close the file
    encoded_file.close();
    
}

string decipher(int key, string encrypted_text){
    
    // setting alphabet
    
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string decoded_text;
    string letter;
    
    
}


