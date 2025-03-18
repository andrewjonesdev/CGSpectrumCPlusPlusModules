// RecursiveDiamond.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
using namespace std;


void diamond(int size, int upperLimit, int lowerLimit, bool container[][200]) {
	int rows = size * 2 + 1;
	if (upperLimit == size) {
		container[rows - size - 1][lowerLimit] = true;
		container[rows - size - 1][upperLimit] = true;
	}
	else {

		container[size - lowerLimit][lowerLimit] = true;
		container[size - lowerLimit][upperLimit] = true;
		container[size + lowerLimit][lowerLimit] = true;
		container[size + lowerLimit][upperLimit] = true;
	}

	if (upperLimit == lowerLimit && size%2==0) {
		return;
	}
	else if (upperLimit == (lowerLimit+1) && size % 2 == 1) {
		return;
	}
	return diamond(size, --upperLimit, ++lowerLimit, container);

}
int main()
{
	int operationChoice = 0;
		int number = 0;
		do {
			cout << "Pick a number between 1 and 100!\n";
			cin >> number;
			if (!(number >= 1 && number <= 100))
				cout << number << " is not one between 1 and 100. Please try again: ";
		} while ((!(number >= 1 && number <= 100)));
		bool diamondContainer[201][200] = { false };
		int rows = number * 2 + 1;
		diamond(number, number, 0, diamondContainer);
		for (int i = 0; i <= (number * 2 + 1); i++) {
			for (int j = 0; j <= number; j++) {
				if (!diamondContainer[i][j]) {
					cout << " ";
				}
				else if(diamondContainer[i][j]) {
					cout << "*";
				}
			}
			cout << '\n';
		}

	cout << endl;
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
