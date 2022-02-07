// Cs150.cpp -- Cs150 Utility Function
#include "Cs150.h"

//Printing the board
void printBoard(char board[3][3])
{
	for (int i = 0;i<3;i++)
	{
		cout << endl;
		for (int j = 0;j<3;j++)
		{
			cout<<"  ";
			cout<<board[i][j];
		}
	}
	cout<<endl;
}


//Choose human character
char humanCharacter(char &human)
{
	while (1)
	{
		string choice;
    cout << "\n" << endl;
		cout << "What would you like your character to be? Enter letter x or  letter o\n";
		cin >> choice;
		if (choice.size()>1)
		{
			cout<<"Invalid input. Please try again.\n";
			continue;
		}
    else if(choice == "1" ||
    choice == "2" ||
    choice == "3" ||
    choice == "4" ||
    choice == "5" ||
    choice == "6" ||
    choice == "7" ||
    choice == "8" ||
    choice == "9")
    {
			cout<<"Invalid input. Please try again.\n";
			continue;
		}
    else {
      human = choice[0];
      return human;
    }
	}
}

//Choose cpu character
char cpuCharacter(char &human, char &comp)
{
	if (human == 'x' || human == 'X')
  {
    comp = 'o';
    cout << "Cpu plays for 'o'." << endl;
    
  }
	else{
    comp = 'x';
    cout << "Cpu plays for 'x'." << endl;
  }
	return comp;
}



// check if the current state is the winning state
char checkWin(char board[3][3])
{
  
	// horizontal, vertical & diagonal through [0][0]
	if (
      (board[0][0] != '1' 
      && board[0][0] == board[0][1] 
      && board[0][0] == board[0][2]) ||
		  (board[0][0] == board[1][0] 
      && board[0][0] == board[2][0]) ||
		  (board[0][0] == board[1][1] 
      && board[0][0] == board[2][2])
      )
      {
        return board[0][0];
      }
	// horizontal, vertical & diagonal through [1][1]
	if (
      (board[1][1] != '5' 
      && board[1][1] == board[1][0] 
      && board[1][1] == board[1][2]) ||
      (board[1][1] == board[0][1] 
      && board[1][1] == board[2][1]) ||
      (board[1][1] == board[0][2] 
      && board[1][1] == board[2][0])
    )
    {	
      return board[1][1];
    }
    // horizontal, vertical & diagonal through [2][2]
	if (
      (board[2][2] != '9' 
      && board[2][2] == board[2][0]
      && board[2][2] == board[2][1]) ||
      (board[2][2] == board[0][2] 
      && board[2][2] == board[1][2])
    )
    {
      return board[2][2];
    }
	return 0;
}

//Place human choice on the board
void placeHumanChoice(char board[3][3], char &human)
{
  int cell;
  while(1)
    {
      cout << "\n" << endl;
      cout << "Enter cell number:" << endl;
      cin >> cell;
      
      // Input validation
      if((cell < 1) || (cell > 9))
      
        cout << "You entered invalid number. Try again." << endl;
      if((cell >=1) && (cell <= 9))
      {
        break;
      }
    }
    switch(cell){
        case 1:
          if(board[0][0] == '1')
          {
            board[0][0] = human;
          }
          else
            cout << "Cell number " << cell << " already occupied. Try again." << endl;
          
          break;
        case 2:
          if(board[0][1] == '2')
          {
            board[0][1] = human;
          }
          else{
            cout << "Cell number " << cell << " already occupied. Try again." << endl;
          }
          break;
        case 3:
          if(board[0][2] == '3')
          {
            board[0][2] = human;
          }
        else
            cout << "Cell number " << cell << " already occupied. Try again." << endl;
          
          break;
        case 4:
          if(board[1][0] == '4')
          {
            board[1][0] = human;
          }
          else
            cout << "Cell number " << cell << " already occupied. Try again." << endl;
          
          break;
        case 5:
          if(board[1][1] == '5')
          {
            board[1][1] = human;
          }
          else{
            cout << "Cell number " << cell << " already occupied. Try again." << endl;
          }
          break;
        case 6:
          if(board[1][2] == '6')
          {
            board[1][2] = human;
          }
          else{
            cout << "Cell number " << cell << " already occupied. Try again." << endl;
          }
          break;
        case 7:
          if(board[2][0] == '7')
          {
            board[2][0] = human;
          }
          else{
            cout << "Cell number " << cell << " already occupied. Try again." << endl;
          }
          break;
        case 8:
          if(board[2][1] == '8')
          {
            board[2][1] = human;
          }
          else{
            cout << "Cell number " << cell << " already occupied. Try again." << endl;
          }
          break;
        case 9:
          if(board[2][2] == '9')
          {
            board[2][2] = human;
          }
          else{
            cout << "Cell number " << cell << " already occupied. Try again." << endl;
          }
          break;
      
    }//end of switch
  }

  //check the middle
void checkMiddle(char board[3][3], char &human, char &comp)
{
  
  if(board[1][1] == '5')
  {
    board[1][1] = comp;
    printBoard(board);
    
  }
  else {
    board[0][0] = comp;
    printBoard(board);
    
  }
}


//pick the move
bool pickMove(char board[3][3], char &human, char &comp)
{
  for(int i =0; i<3; i++)
    for(int j =0; j<3; j++)
    {
      //check row 1 and 2 cell for paired
      if(board[i][j] == board[i][j+1]&&
         board[i][j] == human&&
         board[i][j+2] != comp)
         {
           board[i][j+2] = comp;
           printBoard(board);
           return true;
         }
         
      //check row 2 and 3 cell for paired
      else if(board[i][j+1] == board[i][j+2]&&
              board[i][j+1] == human&&
              board[i][j] != comp)
              {
                board[i][j] = comp;
                printBoard(board);
                 return true;
              }
              
      //check column 1 and 2 cell for paired
       else if(board[i][j] == board[i+1][j]&&
              board[i][j] == human&&
              board[i+2][j] != comp)
              {
                board[i+2][j] = comp;
                printBoard(board);
                 return true;
              }
              
      //check column 2 and 3 cell for paired
      else if(board[i+1][j] == board[i+2][j]&&
              board[i+1][j] == human&&
              board[i][j] != comp)
              {
                board[i][j] = comp;
                printBoard(board);
                 return true;
              }
      //check diagonal for paired
      else if(board[i][j+2] == board[i+1][j+1]&&
              board[i][j+2] == human&&
              board[i+2][j] != comp)
              {
                board[i+2][j] = comp;
                printBoard(board);
                 return true;
              }
      else if(board[i+2][j] == board[i+1][j+1]&&
              board[i+2][j] == human&&
              board[i][j+2] != comp)
              {
                board[i][j+2] = comp;
                printBoard(board);
                 return true;
              }
      
      //check the row 1 and 3 cell for unpaired
      else if(board[i][j] == board[i][j+2]&&
              board[i][j] == human&&
              board[i][j+1] != comp)
              {
                board[i][j+1] = comp;
                printBoard(board);
                 return true;
              }
             
      //check the col 1 and 3 cell for unpaired
      else if(board[i][j] == board[i+2][j]&&
              board[i][j] == human&&
              board[i+1][j] != comp)
              {
                board[i+1][j] = comp;
                printBoard(board);
                 return true;
              }
              
      else if(board[1][0] == '4')
      {
        board[1][0] = comp;
        printBoard(board);
        return true;
      }
      else if(board[2][1] == '8')
      {
        board[2][1] = comp;
        printBoard(board);
        return true;
      }
      else if(board[1][2] == '6')
      {
        board[1][2] = comp;
        printBoard(board);
        return true;
      }
      else if(board[0][1] == '2')
      {
        board[0][1] = comp;
        printBoard(board);
        return true;
      }
      
    }
   
    return false;
}


