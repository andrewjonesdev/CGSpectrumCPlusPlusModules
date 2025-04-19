// Week5Task2StringReversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

string recursiveSwap(string remainder, int count = 0);
int main()
{

	string input = "";
	cout << "Type a sentence: " << endl;
	getline(cin, input);
	cout << recursiveSwap(input) << endl;
	


}

string recursiveSwap(string remainder, int count) {
	//if() remove periods commas etc
	
	string input = remainder;
	int nextFromFront = input.find_first_of(" ");
	int nextFromBack = input.find_last_of(" ");
	remainder = input.substr(nextFromFront+1, input.size() - (input.size()-nextFromBack) - nextFromFront-1);
	cout << "remainder: " << remainder << endl;
	string first = input.substr(0, nextFromFront);
	cout << "first: " << first << endl;
	string last = input.substr(nextFromBack+1, input.size()-nextFromBack-1);
	cout << "last: " << last << endl;
	swap(first, last);
	if (nextFromFront == nextFromBack && count%2 == 0) {
		string newString = first + " " + last;
		return newString;
	}
	else if (remainder.find_first_of(" ") == string::npos) {
		string newString = first + " " + remainder + " " + last;
		return newString;
	}
	else if(remainder.size() > 0 && !(first._Equal(last)) && !(first._Equal(remainder))) {
		string newString = first + " " + recursiveSwap(remainder, count++) + " " + last;
		return newString;
	}
	else if (first._Equal(last) || first._Equal(remainder)) {
		return "";
	}
	else {
		string newString = first + " " + remainder + last;
		return newString;
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
