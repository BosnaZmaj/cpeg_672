// Indy Subasic


#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <time.h>


using namespace std;


//Global Variables


const int x_board_size = 5;
const int y_board_size = 5;

int number_of_bombs;
int total_size_of_grid = x_board_size * y_board_size;

bool loss_condition;
bool win_condition;

//board setup and display to user

class board{
public:
    bool bomb_is_here;
    bool bomb_marked_by_user;
    bool selected_square;
    int neighbor_mine;
    
    board(){
        bomb_is_here = false;
        bomb_marked_by_user = false;
        selected_square = false;
        neighbor_mine = 0;
    }
};

void display_game(board new_game[x_board_size][y_board_size]){
    cout << " ";
    
    for (int column = 0; column < x_board_size; column++){
        cout << column << "|";
    }
    cout << endl;
    
    for (int row = 0; row < x_board_size; row++){
        cout << row << "|";
        
        for (int column = 0; column < x_board_size; column++){
            
            if (new_game[row][column].bomb_marked_by_user && new_game[row][column].bomb_is_here){
            
                cout << "!|";
            
            }else if (new_game[row][column].bomb_marked_by_user){
            
                cout << "?|";
            
            }else if (new_game[row][column].bomb_is_here){
            
                if (win_condition or loss_condition){
            
                    cout << "@|";
            
                } else{
            
                    cout << "_|";
            
                }
            
            }else if (new_game[row][column].selected_square && new_game[row][column].neighbor_mine > 0){
            
                cout << new_game[row][column].neighbor_mine << "|";
            
            }else if (new_game[row][column].selected_square) {
            
                cout << "*|";
            
            }else {
                cout << "_|";
            }
        }
        cout << "\n";
    }
};

void end_of_game(board new_game[x_board_size][y_board_size]){
    
    for (int row = 0; row < y_board_size; row++){
        
        cout << "|";
        
        for (int column = 0; column< x_board_size; column++){
            
            if (new_game[row][column].bomb_is_here){
                
                cout << "@|";
            }else{
                
                cout << "*|";
            }
        }
        
        cout << "\n";
    }
};


void game_win(board new_game[x_board_size][y_board_size]){
    
    for (int row = 0; row < y_board_size; row++){
        
        cout << "|";
        
        for (int column = 0; column < x_board_size; column++){
            
            if (new_game[row][column].bomb_is_here) {
    
                cout << "@|";
            } else{
                
                cout << "*|";
            }
        }
        
        cout << "\n";
    }
}

