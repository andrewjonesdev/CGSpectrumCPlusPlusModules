// Week3Task2OddOrEven.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <cstdlib>
#include <chrono>
using namespace std;

int randomNumber();
string OddOrEven(int number);
bool IsEven(int number);


int main()
{
	int operationChoice = 0;
	do {
		int random = randomNumber();
		// string result = OddOrEven(random);
		// cout << "The number " << random << " is an " << result << " number!" << endl;
		cout << "The number " << random << " is an " << (IsEven(random) ? "EVEN" : "ODD") << " number!" << endl;
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

int randomNumber() {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	default_random_engine engine(seed);
	uniform_int_distribution<int> distribution(1, 100);
	return distribution(engine);
}

string OddOrEven(int number) {
	return abs(number) % 2 == 0 ? "EVEN" : "ODD";
}
bool IsEven(int number) {
	return abs(number) % 2 == 0;
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
