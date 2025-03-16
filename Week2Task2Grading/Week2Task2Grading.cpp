// Week2Task2Grading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    float grade = 0.0f;
    cout << "Enter your grade" << endl;;
    cin >> grade;
    if (grade > 90.0f) {

        cout << "Your " << grade << " is an A" << endl;;
    }
    else if (grade > 80.0f) {

        cout << "Your " << grade << " is a B" << endl;;
    }
    else if (grade > 70.0f) {

        cout << "Your " << grade << " is a C" << endl;;
    }
    else if (grade > 60.0f) {

        cout << "Your " << grade << " is a D" << endl;;
    }
    else if (grade > 0.0f) {

        cout << "Your " << grade << " is a F" << endl;;
    }
    else {

        cout << "Your " << grade << " is an U" << endl;;
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
