# Tic Tac Toe

## Challenge
Program a tic tac toe game. 

## Method
### 1. Constructing and Printing the Board
The board was first made by creating a string array, containing an array which in turn, contained 5 strings each. So it looked something like this: 
```
string board[5][5] = 
{
    {" 1 ", "|", " 2 ", "|", " 3 "},
    {"---", "|", "---", "|", "---"},
    {" 4 ", "|", " 5 ", "|", " 6 "},
    {"---", "|", "---", "|", "---"},
    {" 7 ", "|", " 8 ", "|", " 9 "}
};
```
The locations in the string were then accessed by the individual indexes of the rows and columns. This is also how they were updated. The board was then printing in a for loop for every row. 

### 2. Game Over? 
The program continually checks if the locations which are considered the 'boxes' are filled such so that any row, column or diagonal is filled with the same character. If so, the game is over and which ever character has filled the 'boxes' has won the game. Like so: 
```
if ( 
            board[i][0] == board[i][2] && board[i][2] == board[i][4] ||
            board[0][i] == board[2][i] && board[2][i] == board[4][i] ||
            board[0][0] == board[2][2] && board[2][2] == board[4][4] ||
            board[4][0] == board[2][2] && board[2][2] == board[0][4]
        )
```

### 3. Taking Turns
Becuase each slot in the board is labled 1-9, it was straight forward (but complicated) to turn the int input from the player into the respective row and column coordinates. For the case of the computer, the number is randomly generated from 1-9. 

#### Issue 1: 
The primary problem was what if the inputs from the computer overlapped the user and visa versa? Well it was pretty straightforward to solve, but still very complex. Simply check if the position is currently filled by any character i.e. ` X ` or ` O `. If it is, then run the turn function again and inform the user of the overlap. Do this every time.

As for the input of the computer, randomly generate another number again. 
