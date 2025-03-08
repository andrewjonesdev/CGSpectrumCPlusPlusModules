// Task2UnitConversionChallenge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	cout << "Converion Menu:" << endl;
	cout << "(1) Inches to Feet:" << endl;
	cout << "(2) Inches to Meters:" << endl;
	int choice;
	int inches = 0;
	int feet = 0;
	int remainingInches = 0;
	float meters = 0.0f;
	cin >> choice;
	if (choice == 1) {
		cout << "Inches to Feet:" << endl;
		cout << "How many Inches: ";
		cin >> inches;
		feet = inches / 12;
		remainingInches = inches % 12;

		cout << " The " << inches << " converted to " << feet << " feet and " << remainingInches << " inches." << endl;
		

	}
	else if (choice == 2) {
		cout << "Inches to Meters:" << endl;
		cout << "How many Inches: ";
		cin >> inches;
		meters = inches * .0254f;

		cout << " The " << inches << " converted to " << meters << " meters." << endl;
	}
	else {
		cout << "You did not select a valid option. Goodbye." << endl;
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
