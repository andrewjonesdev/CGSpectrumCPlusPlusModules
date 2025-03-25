// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <tuple>
using namespace std;
void displayBoard(char board[3][3]);
bool isWinner(char board[3][3], bool isPlayerOne);
bool canPlaceMark(char board[3][3], tuple<int, int> coordinates);

int main()
{
	int playerOneOperationChoice = 0;
	int playerTwoOperationChoice = 0;
	bool isPlayerOne = true;
	int numberOfTurns = 0;
	do {

		char board[3][3] = {};
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				board[i][j] = ' ';
			}
		}
		do {
			displayBoard(board);
			int x = 0;
			int y = 0;
			string player = isPlayerOne ? "Player One" : "PlayerTwo";
			do {
				cout << player << ": Pick the column number to put your " << (isPlayerOne ? "X " : "O ") << "\n";
				cin >> x;

				if (!(x >= 1 && x <= 3))
					cout << player << " is not a column on the map. Please try again: ";
			} while (!(x >= 1 && x <= 3));
			do {
				cout << player << ": Pick the row number to put your " << (isPlayerOne ? "X " : "O ") << "\n";
				cin >> y;
				if (!(y >= 1 && y <= 3))
					cout << player << " is not a row on the map. Please try again: ";
			} while (!(y >= 1 && y <= 3));
			if (canPlaceMark(board, make_tuple(x, y))) {
				board[y - 1][x - 1] = isPlayerOne ? 'X' : 'O';
				if (isWinner(board, isPlayerOne)) {
					displayBoard(board);
					cout << player << ": Wins\n";
				}
				isPlayerOne = !isPlayerOne;
			}
			else {
				cout << endl;
				cout << isPlayerOne << "You can't place your mark there. Please try again." << endl;
			}
			if (++numberOfTurns == 9 && !isWinner(board, isPlayerOne)){
				cout << "You guys tied. Game Over" << endl;
			}
		} while (!(isWinner(board, true) || isWinner(board, false) || numberOfTurns == 9));

		do {
			cout << "Player 1: Do you want to play again?\n";
			cout << "1. Yes\n";
			cout << "2. No\n";

			cout << "You entered: ";
			cin >> playerOneOperationChoice;

			if (!(playerOneOperationChoice >= 1 && playerOneOperationChoice <= 2))
				cout << "Player One, " << playerOneOperationChoice << " is not one of the 2 choices. Please try again: ";
		} while (!(playerOneOperationChoice >= 1 && playerOneOperationChoice <= 2));
		if (playerOneOperationChoice == 1) {
			do {
				cout << "Player 2: Do you want to play again?\n";
				cout << "1. Yes\n";
				cout << "2. No\n";

				cout << "You entered: ";
				cin >> playerTwoOperationChoice;

				if (!(playerTwoOperationChoice >= 1 && playerTwoOperationChoice <= 2))
					cout << "Player Two, " << playerTwoOperationChoice << " is not one of the 2 choices. Please try again: ";
			} while (!(playerTwoOperationChoice >= 1 && playerTwoOperationChoice <= 2));
		}
		cout << endl;
	} while (playerOneOperationChoice == 1 && playerTwoOperationChoice == 1);

}
void displayBoard(char board[3][3]) {
	cout << endl;
	cout << "  1 2 3" << endl;
	for (int i = 0; i < 3; i++) {
		cout << i + 1 << " ";
		for (int j = 0; j < 3; j++) {
			if (j < 2) {
				cout << board[i][j] << '|';
			}
			else {

				cout << board[i][j] << endl;
			}
		}
		if (i < 2) {
			cout << "  _____" << endl;
		}
	}
}

bool isWinner(char board[3][3], bool isPlayerOne) {
	//horizontal check
	char playerChar = isPlayerOne ? 'X' : 'O';

	for (int i = 0; i < 3; i++) {
		if (board[i][0] == playerChar && board[i][1] == playerChar && board[i][2] == playerChar) {
			return true;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (board[0][i] == playerChar && board[1][i] == playerChar && board[2][i] == playerChar) {
			return true;
		}
	}

	if (board[0][0] == playerChar && board[1][1] == playerChar && board[2][2] == playerChar) {
		return true;
	}

	if (board[0][2] == playerChar && board[1][1] == playerChar && board[2][0] == playerChar) {
		return true;
	}

	return false;
}
bool canPlaceMark(char board[3][3], tuple<int, int> coordinates) {
	int x, y;
	tie(x, y) = coordinates;
	if (board[y - 1][x - 1] == ' ') {
		return true;
	}
	else {
		return false;
	}
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
