// Indy Subasic


#include <cstdlib>
#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <random>


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
    bool bomb_location;
    bool bomb_marked_by_user;
    bool selected_square;
    int neighbor_mine;
    
    board(){
        bomb_location = false;
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
            
            if (new_game[row][column].bomb_marked_by_user && new_game[row][column].bomb_location){
            
                cout << "!|";
            
            }else if (new_game[row][column].bomb_marked_by_user){
            
                cout << "?|";
            
            }else if (new_game[row][column].bomb_location){
            
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
            
            if (new_game[row][column].bomb_location){
                
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
            
            if (new_game[row][column].bomb_location) {
    
                cout << "@|";
            } else{
                
                cout << "*|";
            }
        }
        
        cout << "\n";
    }
}

void bomb_placement(board new_game[x_board_size][y_board_size], int bomb){
    
    for (int i=0; i < bomb; i++){
        
        srand(time(nullptr));
        
        int bomb_row_placement = rand()%x_board_size;
        int bomb_column_placement = rand()%y_board_size;
        
        if (!new_game[bomb_row_placement][bomb_column_placement].bomb_location){
            
            new_game[bomb_row_placement][bomb_column_placement].bomb_location=true;
        }else{
            
            i--;
        }
    }
};

void place_marker(board new_game[x_board_size][y_board_size], int row, int column){
    
    new_game[row][column].bomb_marked_by_user=true;
    
};

void clicked_square(board new_game[x_board_size][y_board_size], int row, int column){
    
    if (new_game[row][column].bomb_location){
        
        win_condition = false;
        loss_condition = true;
        new_game[row][column].selected_square = true;
        
        end_of_game(new_game);
        
        cout << "BOOOOMMMM!!!!!!!!\n";
        cout << "SORRY, YOU LOST. PICK UP YOUR PIECES AND RESTART GAME TO PLAY AGAIN!!!\n";
        cout << endl;
    
        int adjacent_mine_count = 0;
    
    }
    
    else{
        
        if (new_game[row][column].bomb_marked_by_user){
            
            !new_game[row][column].bomb_marked_by_user;
        }
    
        
        if (row == 0 && column == 0){
        
            if (!new_game[row + 1][column].bomb_location){
                
                new_game[row + 1][column].selected_square = true;
                
            }else{
                
                adjacent_mine_count++;
            };
            
            if (!new_game[row][column + 1].bomb_location){
                
                new_game[row][column + 1].selected_square = true;
            
            }else{
                
                adjacent_mine_count++;
            };
            
            if (!new_game[row + 1][column + 1].bomb_location){
                
                new_game[row + 1][column + 1].selected_square = true;
                
            }else{
                
                adjacent_mine_count++;
                
            };
            
            if (adjacent_mine_count > 0){
                
                new_game[row][column].neighbor_mine = adjacent_mine_count;
            
            }
        }
        
        else if (row == x_board_size - 1 && column == y_board_size - 1 ){
    
            if (!new_game[row - 1][column].bomb_location){
        
                new_game[row - 1][column].selected_square = true;
        
            }else{
        
                adjacent_mine_count++;
            };
    
            if (!new_game[row][column - 1].bomb_location){
        
                new_game[row][column - 1].selected_square = true;
        
            }else{
        
                adjacent_mine_count++;
            };
    
            if (!new_game[row - 1][column - 1].bomb_location){
        
                new_game[row - 1][column - 1].selected_square = true;
        
            }else{
        
                adjacent_mine_count++;
        
            };
    
            if (adjacent_mine_count > 0){
        
                new_game[row][column].neighbor_mine = adjacent_mine_count;
        
            }
        }
        
        else if (row == 0 && column == y_board_size - 1){
    
            if (!new_game[row + 1][column].bomb_location){
        
                new_game[row + 1][column].selected_square = true;
        
            }else{
        
                adjacent_mine_count++;
            };
    
            if (!new_game[row][column - 1].bomb_location){
        
                new_game[row][column - 1].selected_square = true;
        
            }else{
        
                adjacent_mine_count++;
            };
    
            if (!new_game[row + 1][column - 1].bomb_location){
        
                new_game[row + 1][column - 1].selected_square = true;
        
            }else{
        
                adjacent_mine_count++;
        
            };
    
            if (adjacent_mine_count > 0){
        
                new_game[row][column].neighbor_mine = adjacent_mine_count;
        
            }
        }
        
        else if (column == 0 && row == x_board_size - 1 ){
    
            if (!new_game[row][column + 1].bomb_location){
        
                new_game[row][column + 1].selected_square = true;
        
            }else{
        
                adjacent_mine_count++;
            };
    
            if (!new_game[row - 1][column].bomb_location){
        
                new_game[row - 1][column].selected_square = true;
        
            }else{
        
                adjacent_mine_count++;
            };
    
            if (!new_game[row - 1][column + 1].bomb_location){
        
                new_game[row - 1][column + 1].selected_square = true;
        
            }else{
        
                adjacent_mine_count++;
        
            };
    
            if (adjacent_mine_count > 0){
        
                new_game[row][column].neighbor_mine = adjacent_mine_count;
        
            }
        }
        
        else if (row == 0){
    
            if (!new_game[row + 1][column].bomb_location){
        
                new_game[row + 1][column].selected_square = true;
        
            }else{
        
                adjacent_mine_count++;
            };
    
            if (!new_game[row][column + 1].bomb_location){
        
                new_game[row][column + 1].selected_square = true;
        
            }else{
        
                adjacent_mine_count++;
            };
    
            if (!new_game[row][column - 1].bomb_location){
        
                new_game[row][column - 1].selected_square = true;
        
            }else{
        
                adjacent_mine_count++;
        
            }
            
            if (!new_game[row + 1][column + 1].bomb_location){
                
                new_game[row + 1][column + 1].selected_square = true;
            
            }else{
                
                adjacent_mine_count++;
            }
            
            if (!new_game[row + 1][column - 1].bomb_location){
                
                new_game[row + 1][column -1].selected_square = true;
            }
    
            if (adjacent_mine_count > 0){
        
                new_game[row][column].neighbor_mine = adjacent_mine_count;
        
            }
        }
        
        else if (column == 0){
    
            if (!new_game[row - 1][column].bomb_location){
        
                new_game[row - 1][column].selected_square = true;
        
            }else{
        
                adjacent_mine_count++;
            };
    
            if (!new_game[row + 1][column].bomb_location){
        
                new_game[row + 1][column].selected_square = true;
        
            }else{
        
                adjacent_mine_count++;
            };
    
            if (!new_game[row][column + 1].bomb_location){
        
                new_game[row][column + 1].selected_square = true;
        
            }else{
        
                adjacent_mine_count++;
        
            }
    
            if (!new_game[row - 1][column + 1].bomb_location){
        
                new_game[row - 1][column + 1].selected_square = true;
        
            }else{
        
                adjacent_mine_count++;
            }
    
            if (!new_game[row + 1][column + 1].bomb_location){
        
                new_game[row + 1][column + 1].selected_square = true;
            }
    
            if (adjacent_mine_count > 0){
        
                new_game[row][column].neighbor_mine = adjacent_mine_count;
        
            }
            
        }
        
        else if (row == x_board_size - 1){
    
            if (!new_game[row - 1][column].bomb_location){
        
                new_game[row - 1][column].selected_square = true;
        
            }else{
        
                adjacent_mine_count++;
            };
    
            if (!new_game[row][column + 1].bomb_location){
        
                new_game[row][column + 1].selected_square = true;
        
            }else{
        
                adjacent_mine_count++;
            };
    
            if (!new_game[row][column - 1].bomb_location){
        
                new_game[row][column - 1].selected_square = true;
        
            }else{
        
                adjacent_mine_count++;
        
            }
    
            if (!new_game[row - 1][column - 1].bomb_location){
        
                new_game[row + 1][column - 1].selected_square = true;
        
            }else{
        
                adjacent_mine_count++;
            }
    
            if (!new_game[row + 1][column - 1].bomb_location){
        
                new_game[row + 1][column -1].selected_square = true;
            }
    
            if (adjacent_mine_count > 0){
        
                new_game[row][column].neighbor_mine = adjacent_mine_count;
        
            }
        }
        
        else if (column == y_board_size - 1){
            
    
            if (!new_game[row - 1][column].bomb_location){
        
                new_game[row - 1][column].selected_square = true;
        
            }else{
        
                adjacent_mine_count++;
            };
    
            if (!new_game[row + 1][column].bomb_location){
        
                new_game[row + 1][column].selected_square = true;
        
            }else{
        
                adjacent_mine_count++;
            };
    
            if (!new_game[row][column - 1].bomb_location){
        
                new_game[row][column - 1].selected_square = true;
        
            }else{
        
                adjacent_mine_count++;
        
            }
    
            if (!new_game[row - 1][column - 1].bomb_location){
        
                new_game[row - 1][column - 1].selected_square = true;
        
            }else{
        
                adjacent_mine_count++;
            }
    
            if (!new_game[row + 1][column - 1].bomb_location){
        
                new_game[row + 1][column -1].selected_square = true;
            }
    
            if (adjacent_mine_count > 0){
        
                new_game[row][column].neighbor_mine = adjacent_mine_count;
        
            }
        }
        
        else{
    
            if (!new_game[row - 1][column].bomb_location){
        
                new_game[row - 1][column].selected_square = true;
        
            }else{
        
                adjacent_mine_count++;
            };
    
            if (!new_game[row + 1][column].bomb_location){
        
                new_game[row + 1][column].selected_square = true;
        
            }else{
        
                adjacent_mine_count++;
            };
    
            if (!new_game[row][column + 1].bomb_location){
        
                new_game[row][column + 1].selected_square = true;
        
            }else{
        
                adjacent_mine_count++;
        
            }
    
            if (!new_game[row][column - 1].bomb_location){
        
                new_game[row][column - 1].selected_square = true;
        
            }else{
        
                adjacent_mine_count++;
            }
    
            if (!new_game[row - 1][column + 1].bomb_location){
        
                new_game[row - 1][column + 1].selected_square = true;
            }else{
                
                adjacent_mine_count++;
            }
            
            if (!new_game[row - 1][column - 1].bomb_location){
                
                new_game[row - 1][column - 1].selected_square = true;
            
            }else{
                
                adjacent_mine_count++;
            }
            
            if (! new_game[row + 1][column + 1].bomb_location){
                
                new_game[row + 1][column + 1].selected_square = true;
            }else{
                
                adjacent_mine_count++;
                
            }
            
            if (!new_game[row + 1][column - 1].bomb_location){
                
                new_game[row + 1][column - 1].selected_square = true;
                
            }else{
                
                adjacent_mine_count++;
            }
    
            if (adjacent_mine_count > 0){
        
                new_game[row][column].neighbor_mine = adjacent_mine_count;
        
            }
        }
    }
}