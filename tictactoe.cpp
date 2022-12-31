//introducing necessary libraries.
#include <iostream>
#include <unistd.h>
using namespace std;

//Declaring structs followed by an array. 
struct coords 
{
    int row, column;
};

//Array represents a board, each item in the array contains an another array consisting of 5 strings each. 
string board[5][5] = 
{
    {" 1 ", "|", " 2 ", "|", " 3 "},
    {"---", "|", "---", "|", "---"},
    {" 4 ", "|", " 5 ", "|", " 6 "},
    {"---", "|", "---", "|", "---"},
    {" 7 ", "|", " 8 ", "|", " 9 "}
};

//Prints the board array per row. 
void print_board() 
{
    cout << endl;
    for (int i = 0; i < 5; i++) 
    {
        for (int n = 0; n < 5; n++)
        {
            cout << board[i][n];
        }
        cout << endl;
    }
    cout << endl;
};

//Checks if any of the conditions to complete the game have been met. 
void game_over(string character)
{
    int count = 0;
    for (int i = 0; i <= 4; i += 2)
    {
        //Checks if any of the same type (" X " or " O ") have filled any row, column or diagonal. 
        if ( 
            board[i][0] == board[i][2] && board[i][2] == board[i][4] ||
            board[0][i] == board[2][i] && board[2][i] == board[4][i] ||
            board[0][0] == board[2][2] && board[2][2] == board[4][4] ||
            board[4][0] == board[2][2] && board[2][2] == board[0][4]
        )
        {
            //If any of the above conditions are met, 1 is added to the count. 
            count++;
        }
    }
    if (count > 0)
    //The game ends with a "Congratulations" if the count is above 0.
    {
        cout << "CONGRATULATIONS" << character << "WON!!" << endl;
        exit(0);
    }
}

//Updates the board[][] array using the indexes obtained from the user/ computer input.
bool players_turn(coords player, int num, string character) 
{
    //Created a formula to calculate which row and which column the player's character will be substituted into. 
    if (num % 3 == 0) 
    {
        player.row = (num / 3 - 1) * 2;
        player.column = 4;
    }
    else 
    {
        player.row = (num / 3) * 2;
        player.column = (num % 3 - 1) * 2;
    }

    //If there is already a character (" X " or " O ") in the player's chosen position, 
    //it will not substitute the character and return false instead. 
    if (board[player.row][player.column] == " X " ||
    board[player.row][player.column] == " O ")
    {
        return false;
    }
    else
    {
        //Using the indexes generated from the formula, it will substitute the character
        //into the according row and column. 
        board[player.row][player.column] = character;
        print_board();
        //After every turn, whether the comp or user, it will check if either has won the game. 
        game_over(character);
        return true;
    }
}

void users_turn() 
{
    coords user;
    int input;

    cout << "Where do you want to put your character down? ";
    cin >> input;

    //The following line only CHECKS if the position is free. If it is not, it will call on the function again. 
    if (players_turn(user, input, " X ") == false)
    {
        cout << "That position is currently occupied. Please try again." << endl;
        users_turn();
    }
    //If the position is free, it will input the character. 
    else
    {
        players_turn(user, input, " X ");
    }
}

void computers_turn() 
{
    coords computer;
    int input;

    cout << "Computer's turn: " << endl;
    //Will randomly generate a number from 1-9 based on the time. 
    //HOWEVER, sleep(1) was implemented because if the randomly choosen position is taken,
    //The time-based generator needs to wait before outputting another number
    //otherwise it will output the same number again. 
    srand(time(NULL));
    sleep(1);
    input = rand() % 9 + 1;

    //The following line only CHECKS if the position is free. If it is not, it will call on the function again. 
    if (players_turn(computer, input, " O ") == false)
    {
        computers_turn();
    }
    else
    {
        players_turn(computer, input, " O ");
    }
}

//Main function.
int main() 
{
    print_board();

    //Always running the turns in concession.
    while (true)
    {
        users_turn();
        computers_turn();
    }
}