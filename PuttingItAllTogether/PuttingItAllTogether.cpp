// PuttingItAllTogether.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    // Prompt for name
    cout << "Please enter your name: ";

    // Get the name
    string name;
    cin >> name;

    // Prompt user for  year of birth
    cout << "Please enter year of birth: ";

    // Get the year of birth
    int yearOfBirth;
    cin >> yearOfBirth;

    // Prompt user for the current year
    cout << "Please enter the current year: ";

    // Get the current year
    int currentYear;
    cin >> currentYear;

    // Display info to the user
    int age = currentYear - yearOfBirth;
    cout << name << " you are " << age << " years old!" << endl;
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
