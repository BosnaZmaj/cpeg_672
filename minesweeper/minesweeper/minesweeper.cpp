//
// Created by BosnaZmaj on 4/28/2020.
//

#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <time.h>

using namespace std;

//Basic setup

const int x_board_size = 5;
const int y_board_size = 5;

int number_of_bombs;

int total_grid_size = x_board_size * y_board_size;

bool loss_condition;
bool win_condition;

class GameBoard{

public:
    bool bomb_is_here;
    bool bomb_marked_by_player;
    bool clicked_cell;
    int adjacent_mines;
    
    //blank board setup
    
    GameBoard(void){
        bomb_is_here = false;
        bomb_marked_by_player = false;
        clicked_cell = false;
        adjacent_mines = 0;
    }
};

//Displaying the board on screen

void display_game(GameBoard() new_game[x_board_size][y_board_size]){
    cout << " ";
    
    for (int column = 0; column<x_board_size; column++){
        cout << column < "|";
    }
    cout << endl
    
    for (int row = 0; row<y_board_size; row++){
        cout << row << "|";
        
        for int(column = 0; column<x_board_size; column++){
            if (new_game[row][column].bomb_marked_by_player && new_game[row][column].bomb_is_here) {
                cout << "!|"
            }
        }
    }
};