// Operators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int b = 3;

    int add = a + b; // 13
    int subtract = 10 - b; // 7
    int multiply = a * 3; // 30
    int division = a / b; // 3
    int mod = a % b; // 1
    cout << division << endl;

    float div2 = 10 / 3.0f;
    cout << div2 << endl;
    
    float div3 = a / (float)b;
    cout << div3 << endl;

    int result = 1 + 2 * 3 + 4; // (1 + 6 + 4) = 11
    cout << result << endl;

    int result2 = 1 + (2 * 3) + 4; // (1 + 6 + 4) = 11
    cout << result2 << endl;
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
