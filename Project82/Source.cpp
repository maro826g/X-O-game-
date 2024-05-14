#include <iostream>
using namespace std;

// Global Variables
char board[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
bool game_over = false;
int player_x_score_cvp = 0;
int player_o_score_cvp = 0;
int player_x_score_pvp = 0;
int player_o_score_pvp = 0;

// Functions Initializing
void player_vs_player(int mode);
void computer_vs_player(int mode);
void main_menu();           
void play_again(int mode);

// Display Board Function 
void display_board() {
    system("cls");
    cout << "     |     |     " << endl;
    for (int i = 0; i < 9; i += 3) {
        cout << "  " << board[i] << "  |  " << board[i + 1] << "  |  " << board[i + 2] << endl;
        if (i < 6) cout << "_____|_____|_____" << endl << "     |     |     " << endl;
    }
    cout << "     |     |     " << endl << endl;
}

// Count Number of Occurrences of a (X, O) char in Game Board
int count_board(char symbol) {
    int total = 0;
    for (int i = 0; i < 9; i++) { 

        if (board[i] == symbol) {
            total++;
        }
    }
    return total;
}

// Checking Who Is The Winner Function
char check_win() {
    char winner = ' ';

    // Rows
    for (int i = 0; i < 9; i += 3) {
        if (board[i] == board[i + 1] && board[i + 1] == board[i + 2]) {
            winner = board[i];
            break;      
        }
    }

    // Columns
    if (winner == ' ') {
        for (int i = 0; i < 3; i++) {
            if (board[i] == board[i + 3] && board[i + 3] == board[i + 6]) {
                winner = board[i];
                break;
            }
        }
            
      
    }

    // Diagonals
    if (board[0] == board[4] && board[4] == board[8])
        winner = board[0];
    else if (board[2] == board[4] && board[4] == board[6])
        winner = board[2];

    // Check for a tie
    int count = count_board('X') + count_board('O');
    if (winner == ' ' && count == 9)
        winner = 'T';

    return winner;
}

// Getting Player Input Function
void player_choice(char player_symbol) {
    int block;
    while (1) {
        cout << "Player " << player_symbol << ", Enter An Empty Block Number (1-9): ";
        cin >> block;   
        block--;
        if (block < 0 || block > 8) {
            cout << "\nInvalid Move! Please Select An Empty Block Number between 1 and 9." << endl;
        }
        else if (board[block] == 'O' || board[block] == 'X') {
            cout << "\nAlready Occupied! Please Select An Empty Block." << endl;
        }
        else {
            board[block] = player_symbol;
            break;
        }
    }
}

// Getting Computer Input Function
void computer_choice() {
    int choice;
    do {
        choice = rand() % 9; // generate a random number from 0 to 8
    } while (board[choice] == 'X' || board[choice] == 'O'); // keep generating until an empty cell is found
    board[choice] = 'O';
}

// Main Function
int main() {
    main_menu();

    return 0;
}

// Computer vs Player Function
void computer_vs_player(int mode) {
    while (!game_over) {
        display_board();
        player_choice('X');
        //system("cls");
        char winner = check_win();
        if (winner == 'T') {
            display_board();
            cout << "The Game Is Draw!\n\n";
            cout << "-----------------------\n";
            cout << "| Player X | Computer |\n";
            cout << "|    " << player_x_score_cvp << "     |     " << player_o_score_cvp << "    |\n";
            cout << "-----------------------\n";
            play_again(mode);
            break;
        }
       // system("cls");
        

        if (winner != ' ' && winner != 'T') {
            display_board();
            cout << "Player X Won!\n\n";
            player_x_score_cvp++;
            cout << "-----------------------\n";
            cout << "| Player X | Computer |\n";
            cout << "|    " << player_x_score_cvp << "     |     " << player_o_score_cvp << "    |\n";
            cout << "-----------------------\n";
            play_again(mode);
            break;
        }

        //system("cls");

        computer_choice();
        winner = check_win();
        if (winner != ' ' && winner != 'T') {
            display_board();
            cout << "Computer Won!\n\n";
            player_o_score_cvp++;
            cout << "-----------------------\n";
            cout << "| Player X | Computer |\n";
            cout << "|    " << player_x_score_cvp << "     |     " << player_o_score_cvp << "    |\n";
            cout << "-----------------------\n";
            play_again(mode);
            break;
        }
    }
}

// Player_vs_Player Function
void player_vs_player(int mode) {
    while (!game_over) {
        display_board();
        player_choice('X');
        system("cls");
        char winner = check_win();
        if (winner == 'T') {
            display_board();
            cout << "The Game Is Draw!\n\n";
            cout << "-----------------------\n";
            cout << "| Player X | Player O |\n";
            cout << "|    " << player_x_score_pvp << "     |     " << player_o_score_pvp << "    |\n";
            cout << "-----------------------\n";
            play_again(mode);
            break;
        }

        if (winner != ' ' && winner != 'T') {
            display_board();
            cout << "Player X Won!\n\n";
            player_x_score_pvp++;
            cout << "-----------------------\n";
            cout << "| Player X | Player O |\n";
            cout << "|    " << player_x_score_pvp << "     |     " << player_o_score_pvp << "    |\n";
            cout << "-----------------------\n";
            play_again(mode);
            break;
        }

        system("cls");

        display_board();
        player_choice('O');
        system("cls");
        winner = check_win();
        if (winner != ' ' && winner != 'T') {
            display_board();
            cout << "Player O Won!\n\n";
            player_o_score_pvp++;
            cout << "-----------------------\n";
            cout << "| Player X | Player O |\n";
            cout << "|    " << player_x_score_pvp << "     |     " << player_o_score_pvp << "    |\n";
            cout << "-----------------------\n";
            play_again(mode);
            break;
        }

        system("cls");

    }
}

// Main Menu Function
void main_menu() {
    int choice;

    cout << "Welcome to Tic Tac Toe" << endl;
    cout << "1. Play vs Computer" << endl;
    cout << "2. Play vs Player" << endl;
    cout << "3. Quit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;

    switch (choice) {
    case 1:
        computer_vs_player(1);
        break;
    case 2:
        player_vs_player(2);
        break;
    case 3:
        cout << "Bye :(" << endl;
        game_over = true;
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        main_menu();
        break;
    }
}

// Play Again Function
void play_again(int mode) {
    char choice;
    cout << "Do you want to play again? (Y/N) ";
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        game_over = false;
        for (int i = 0; i < 9; i++) {
            board[i] = (i + 1) + '0';
        }
        system("cls");
        main_menu();
    }
    else if (choice == 'N' || choice == 'n') {
        game_over = true;
        system("cls");
        cout << "\nThanks For Playing :)\n";
        if (mode == 1) {
            cout << "-----------------------\n";
            cout << "| Player X | Computer |\n";
            cout << "|    " << player_x_score_cvp << "     |     " << player_o_score_cvp << "    |\n";
            cout << "-----------------------\n";
        }
        else {
            cout << "-----------------------\n";
            cout << "| Player X | Player O |\n";
            cout << "|    " << player_x_score_pvp << "     |     " << player_o_score_pvp << "    |\n";
            cout << "-----------------------\n";
        }
        exit(0);
    }
    else {
        cout << "\nPlease Type An Valid Option!\n";
        play_again(mode);
    }
}