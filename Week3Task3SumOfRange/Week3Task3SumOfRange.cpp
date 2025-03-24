// Week3Task3SumOfRange.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <cstdlib>
#include <chrono>
using namespace std;

int sumOfRange(int lowerRange, int upperRange, int currentSum = 0);


int main()
{
	int operationChoice = 0;
	do {
		int lowerRange = 0;
		int upperRange = 0;
		do {
			cout << "Enter a whole number greater than 0" << endl;
			cin >> lowerRange;
			if (lowerRange <= 0) {
				cout << "Invalid input: " << lowerRange << " is not greater than 0. Try again." << endl;
			}
		} while (lowerRange <= 0);
		do {
			cout << "Enter a whole number greater than " << lowerRange << endl;
			cin >> upperRange;
			if (upperRange <= lowerRange) {
				cout << "Invalid input: " << upperRange << " is not greater than " << lowerRange << ". Try again." << endl;
			}
		} while (upperRange <= lowerRange);
		cout << "The sum of numbers between " << lowerRange << " and " << upperRange << " is " << sumOfRange(lowerRange, upperRange) << endl;
		do {
			cout << "Do you want to check another number?\n";
			cout << "1. Yes\n";
			cout << "2. No\n";

			cout << "You entered: ";
			cin >> operationChoice;

			if (!(operationChoice >= 1 && operationChoice <= 2))
				cout << operationChoice << " is not one of the 2 choices. Please try again: ";
		} while (!(operationChoice >= 1 && operationChoice <= 2));
		cout << endl;
	} while (operationChoice == 1);

}

int sumOfRange(int lowerRange, int upperRange, int currentSum) {
	if (lowerRange < upperRange) {
		cout << "lower range: " << lowerRange << endl;
		cout << "upper range: " << upperRange << endl;
		cout << "current sum: " << currentSum << endl;
		return sumOfRange(lowerRange+1, upperRange, (lowerRange + currentSum));
	}
	else {

		cout << "final sum: " << lowerRange + currentSum << endl;
		return lowerRange + currentSum;
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
