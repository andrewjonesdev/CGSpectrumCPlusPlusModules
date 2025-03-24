// Week3Task1Gullible.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	int operationChoice = 0;
	do {
		int number = 0;
		int result = 0;
		for (result; result < 10; result++) {
			cout << "Enter a number other than 5, this is time number " << result +1  << endl;
			
			cin >> number;
			while (number == 5) {
				cout << "Hey you weren’t supposed to enter 5, you got it on try number " << result + 1 << "!" << endl;
				goto play_again_offer;
			}
		}
			cout << "Wow you're more patient than I am, that was " << result << " times, you win!";
		play_again_offer:
		do {
			// Ask the user which operation they would like to perform
			cout << "Do you want to try again?\n";
			cout << "1. Yes\n";
			cout << "2. No\n";

			cout << "You entered: ";
			cin >> operationChoice;

			if (!(operationChoice >= 1 && operationChoice <= 2))
				cout << operationChoice << " is not one of the 2 choices. Please try again: ";
		} while (!(operationChoice >= 1 && operationChoice <= 2));
	} while (operationChoice == 1);
	
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
