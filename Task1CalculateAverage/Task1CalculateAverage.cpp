// Task1CalculateAverage.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    // Ask user to input three numbers
    cout << "How many numbers do you want to average? ";
    int numbers;
    cin >> numbers;
    int sum = 0;
    for (int i = 0; i < numbers; i++) {
        int currentNumberToEnter = i + 1;
        cout << "Insert number " << currentNumberToEnter << ": ";
        int currentNumber;
        cin >> currentNumber;
        sum += currentNumber;
    }
    float average = sum / (float)numbers;
    cout << "The sum of the " << numbers << " numbers is " << sum << endl;
    cout << "The average of the " << numbers << " numbers is " << average << endl;

    // Calculate the sum and divide by 3 to get the average

    // Print the result

    // Bonus Task 
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
