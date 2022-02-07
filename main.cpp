/* Title: Tic-tac-toe game Human vs Computer.
* Author: Elena Mudrakova
* Algorithm:
1. Declare char human
           char comp
2. Create and initialize board[3][3] array
3. Create printBoard() function
4. Create humanCharacter()
5. Ask human to choose the character
6. Validate input

create cpuCharacter() function

create placeHumanChoice()
  ask human to choose the cell
  validate input
  put human charcter in the cell if it's not occupied

create checkWin() function that checks row/col/diagonal if it's filled with same character and returns this character.

create checkMiddle() that checks if the board[1][1] occupied with human, if yes - cpu takes the corner, if no - cpu takes middle

create pickMove() fucntion. It looks for paired (xx) human character and blocks it. Then it looks for unpaired (x x) human character and blocks it. If there is no paired and unpaired, cpu checks cells on the edge and takes first empty cell. 
in main() call:
  printBoard(board);
  humanCharacter(human);
  cpuCharacter(human, comp);
  placeHumanChoice(board, human);
  checkMiddle(board, human, comp);
  int moves;
  create while loop
    placeHumanChoice(board, human);
    checkWin(board);
    pickMove(board, human, comp);
    checkWin(board);
    moves +=2;
  After wile loop check what checkWin() returns and yell the winner
  suggest  to play again
*/
#include "Cs150.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
  char human;
  char comp;
  
  //Create and initialize array for board
  char board[3][3] = {{'1', '2', '3'},
                      {'4', '5', '6'},
                      {'7', '8', '9'}};
  system("clear");
  cout << "Welcome to Tic-Tac-Toe Game Human vs Computer!" << endl;
  
  printBoard(board);
  humanCharacter(human);
  cpuCharacter(human, comp);
  placeHumanChoice(board, human);
  checkMiddle(board, human, comp);
  int moves = 2;

  while(moves < 9 && !checkWin(board))
  {
    placeHumanChoice(board, human);
    checkWin(board);
    pickMove(board, human, comp);
    checkWin(board);
    
    moves +=2;
  }
  
  if(checkWin(board) == comp)
  { 
    char repeat;
    cout << "\n" << endl;
    cout << "Cpu won!" << endl;
    cout << "Try again? Y/N" << endl;
    cin >> repeat;
    if(repeat == 'Y' || repeat == 'y')
    {
      return main();
    }
    else {
      cout << "Bye bye!" << endl;
    }
  }
  else if(checkWin(board) == human)
  {
    cout << "Human won!" << endl;
  }
  else{
    cout << "Draw." << endl;
  }
}

