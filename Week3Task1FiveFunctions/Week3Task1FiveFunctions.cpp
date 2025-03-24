// Week3Task1FiveFunctions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int IncrementByOne(int i);
int MultiplyByTwo(int i);
int IncrementByFour(int i);
int DivideByTwo(int i);
int SubtractOriginalNumber(int i, int originalNum);

int main()
{
	int operationChoice = 0;
	do {
		int number = 0;
		do {
			cout << "Enter a number between 1 and 20" << endl;
			cin >> number;
			if (number > 20 || number < 1) {
				cout << "Invalid response " << number << " is not between 1 and 20 please try again." << endl;

			}

		} while (number > 20 || number < 1);
		;
		int result = SubtractOriginalNumber(DivideByTwo(IncrementByFour(MultiplyByTwo(IncrementByOne(number)))), number); // essentially you're always adding 6 (increment 1 then times by 2 will get that addional 2) 
																														  // adding 4 to get additional 6 then dividing by 2 for the additional 3 when subtracting by itself
		cout << "(((((" << number << "+1)*2)+4)/2)-" << number << "=" << result << endl;
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
int IncrementByOne(int i) {
	return ++i;
}
int MultiplyByTwo(int i) {
	return i * 2;
}
int IncrementByFour(int i) {
	return i + 4;
}
int DivideByTwo(int i) {
	if (i % 2 != 0) {
		cout << "Warning data has been lost the correct number is " << i / 2.0 << " but this number will be truncated to " << i / 2 << endl;
	}
	return i / 2;
}
int SubtractOriginalNumber(int i, int originalNum) {
	return i - originalNum;
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
