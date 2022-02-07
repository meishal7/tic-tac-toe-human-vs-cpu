//Cs150.h -- Cs150 Utility Specification File
#ifndef CS150_H
#define CS150_H
#include <iostream>
#include <string>
using namespace std;

//Description: printBoard(char board[3][3]) prints the board in console
//Precondition: board[3][3] has to be initialized
//Postcondition: board[3][3] is printed to console
void printBoard(char board[3][3]);

//Description: humanCharacter(char &human) allows player to choose a character and validates input
//Precondition: non
//Postcondition: player input is validated and stored in char human
char humanCharacter(char &human);

//Description: cpuCharacter(char &human, char &comp) stores cpu character in char comp depending on what character human choose
//Precondition: char human has to be initialized with humanCharacter()
//Postcondition: cpu character is stored in char comp
char cpuCharacter(char &human, char &comp);

//Description: placeHumanChoice(char board[3][3], char &human) asks player to choose a cell, validates player input and places player character in a cell if it's not occupied.
//Precondition: char human and char board[3][3] have to be initialized before
//Postcondition: human character is placed in a cell
void placeHumanChoice(char board[3][3], char &human);

//Description: checks if board middle is occupied with human
//Precondition: char board[3][3], char &human, char &comp have to be initialized
//Postcondition: if the middle is not occupied, cpu takes the middle, if it's occupied, cpu takes board[0][0]
void checkMiddle(char board[3][3], char &human, char &comp);

//Description: checks if current state is winning state
//Preconditions: char board[3][3] has to be initialized
//Postcondition: returns false if current state is not winning state, returns true and returns char if current state is winning state
char checkWin(char board[3][3]);

//Description: picks right move for cpu
//Preconditions: char board[3][3], char &human, char &comp have to be initialized
//Postcondition: cpu character placed in a cell
bool pickMove(char board[3][3], char &human, char &comp);

#endif
                                                                                                          