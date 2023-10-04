/*

  Manasvi Meka
  Tic tac toe project. user inputs the name of row and column number and the X and O are displayed accordingly.

  - Used Java Code from CS 161
  - Snippet of code about memset was from geeksforgeeks (https://www.geeksforgeeks.org/memset-in-cpp/) and stack exchange (https://codereview.stackexchange.com/questions/123200/tic-tac-toe-c)

  Date last modified: Oct 3rd 2023. 
  
 */ 
#include <iostream>
#include <cstring>

using namespace std;

// Constants
char BLANK = ' ';
char XMOVE = 'X';
char OMOVE = 'O';
int XTURN = 0;
int OTURN = 1;
 

// Function to print the game board
void printBoard(char board[3][3]) {
    cout << "\t1\t2\t3" << endl;
    for (int row = 0; row < 3; row++) {
        char rowLabel = 'a' + row;
	 
	cout << rowLabel << "\t";
        for (int column = 0; column < 3; column++) {
            cout << board[row][column] << "\t";
        }
        cout << endl;
    }
}


//listing out all constraints for win

bool checkWin(char board[3][3], int player){

  if(board[0][0] == false && board[0][1] == false && board[0][2] == false){
    return true; 
  }

  if (board[0][0] == player && board [1][0] == player && board[2][0] == player) {
			return true; // 1st column
		}
		if (board[0][0] == player && board [1][1] == player && board[2][2] == player) {
			return true; // diagonal down
		}
		if (board[2][0] == player && board [1][1] == player && board[0][2] == player) {
			return true; // diagonal up
		}
		if (board[1][0] == player && board [1][1] == player && board[1][2] == player) {
			return true; // second row 
		}
		if (board[0][1] == player && board [1][1] == player && board[2][1] == player) {
			return true; //second column 
		}
		if (board[0][2] == player && board [1][2] == player && board[2][2] == player) {
			return true; // 3 row 
		}
		if (board[2][0] == player && board [2][1] == player && board[2][2] == player) {
			return true; // 3rd column
		}
  
		return false; 


		}



bool checkTie(char board[3][3]){

  for (int i =0; i < 3; i++){
    for (int j = 0; j < 3; j++){

      if (board[i][j] == BLANK){
	return false; 
      }


    }
  }

  return true; 

}




int main(){

    bool stillPlaying = true;
    int xWins = 0;
    int oWins = 0;
    int ties = 0;

    while (stillPlaying) {
        char board[3][3];  // Initialize a new board for each game
        memset(board, BLANK, sizeof(board)); // Initialize the board to BLANK
        int turn = XTURN;
        
        while (!checkWin(board, XMOVE) && !checkWin(board, OMOVE) && !checkTie(board)) {
           printBoard(board);
            char input[3];
	    cout << "please enter a letter and a number like a1 or b3" << endl; 
            cin.getline(input, sizeof(input));
            if (strlen(input) != 2) {
               cout << "Enter a letter and then a number!" << endl;
            } else if (input[0] != 'a' && input[0] != 'b' && input[0] != 'c') {
                cout << "Row must be a, b, or c" << endl;
            } else if (input[1] != '1' && input[1] != '2' && input[1] != '3') {
                cout << "Column must be 1, 2, or 3" << endl;
            } else {
                int row = input[0] - 'a';
                int column = input[1] - '1'; //using c++ ascii values since 'a' is equivalent to 1 and creating char arrays
                if (board[row][column] == BLANK) {
                    if (turn == XTURN) {
                        board[row][column] = XMOVE;
                        turn = OTURN;
                    } else {
                        board[row][column] = OMOVE;
                        turn = XTURN;
                    }
                } else {
                    cout << "Try a different place since there is already a piece there!" << endl;
                }
            }
	    }
	if (checkWin(board,XMOVE)){
	  cout << "X wins" << endl;
	  xWins++; 

	}
	else if(checkWin(board,OMOVE)){
	   cout << "O wins" << endl;
	   oWins++;

	}
	else {
	  cout << "It's a tie" << endl;
          ties++;

	}

	 cout << "X wins: " << xWins << " O Wins: " << oWins << " Ties: " << ties << endl;
        cout << "Play again? Please type either y or n: ";

	   char yn;
        cin >> yn;
        cin.ignore();
        if (yn != 'y') {
            stillPlaying = false; //if yes or no doesn't equal y terminate the process and print thanks
            cout << "Thanks for playing." << endl;
        }

   
}

    return 0; 
}


