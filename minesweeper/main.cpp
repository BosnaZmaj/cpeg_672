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
        cout << "\n";
        cout << "SORRY, YOU LOST. PICK UP YOUR PIECES AND RESTART GAME TO PLAY AGAIN!!!\n";
        cout << endl;
    
    
    }
    
    else{
        
        if (new_game[row][column].bomb_marked_by_user){
            
            !new_game[row][column].bomb_marked_by_user;
        }
    
        int adjacent_mine_count = 0;
    
    
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

void review_win(board new_game[x_board_size][y_board_size]){
    
    int total = total_size_of_grid - number_of_bombs;
    int win = 0;
    
    for (int y = 0; y < y_board_size; y++){
        for (int x=0; x < x_board_size; x++){
            if (new_game[y][x].selected_square && !new_game[y][x].bomb_location){
                
                win++;
            }
        }
        
        if (total == win){
            
            win_condition =true;
            
            cout << "WOW YOU HAVE NOT EXPLODED!!!!!!! GOOD JOB!!!!!!" << endl;
        }
    }
};

int main(){
    
    !loss_condition;
    !win_condition;
    
    int choice;
    int row;
    int column;
    
    cout << "|------Minesweeper------|\n";
    cout << "|                       |\n";
    cout << "|                       |\n";
    cout << "| Game Instructions     |\n";
    cout << "|-----------------------|\n";
    cout << "| @ = Bomb              |\n";
    cout << "| ? = Maybe a Bomb      |\n";
    cout << "| ! = Definitely a Bomb |\n";
    cout << "| __ = No Bomb          |\n";
    cout << "|-----------------------|\n";
    cout << "\n";
    
    cout << "How many bombs would you like?\n";
    cin >> number_of_bombs;
    
    while (number_of_bombs >= total_size_of_grid){
        
        cout << "Amount of mines must be between 1 and total size of grid" << total_size_of_grid << ": \n";
        cin >> number_of_bombs;
    }
    
    board new_game[x_board_size][y_board_size];
    bomb_placement(new_game, number_of_bombs);
    
    while (!loss_condition && !win_condition){
        display_game(new_game);
        
        cout << "------------Menu------------\n";
        cout << "|     1 = Reveal Square    |\n";
        cout << "|     2 = Mark Square      |\n";
        cout << "----------------------------\n";
        cout << "\n";
        cin >> choice;
        
        if (choice == 1){
            cout << "Row: ";
            cin >> row;
            cout << "\n";
            
            cout << "Column: ";
            cin >> column;
            cout << "\n";
            
            cout << "Revealed Squares: \n";
            cout << "Row    Column\n";
            cout << row  << column;
            cout << "\n";
            
            clicked_square(new_game, row, column);
            review_win(new_game);
        }
        
        else if (choice == 2){
            
            display_game(new_game);
            
            cout << "Select Row: ";
            cin >> row;
            cout << "\n";
            
            cout << "Select Column: ";
            cin >> column;
            cout << "\n";
            
            cout << "Selected Squares: \n";
            cout << "Row     Column\n";
            cout << row << column;
            cout << "\n";
            
            place_marker(new_game, row, column);
            review_win(new_game);
    }
        else{
        
            cout << "Not cool dude! Where did I say you can make that choice?";
            cout << "\n";
        }
    }
}