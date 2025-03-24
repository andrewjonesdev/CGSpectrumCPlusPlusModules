// Week3Task2ArrayStatistics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

static int sum(vector<int> numbers);
static float average(vector<int> numbers);
static int largest(vector<int> numbers);
static int smallest(vector<int> numbers);
static tuple<int, int> evensAndOdds(vector<int> numbers);

int main()
{
    int operationChoice = 0;
    do {
    int numberOfNumbers = 0;
    do {
        cout << "How many numbers do you want to enter?" << endl;
        cin >> numberOfNumbers;
        if (numberOfNumbers<=1)
            cout << numberOfNumbers << " is an invalid choice. You need to enter a number larger than 1. Please try again: ";
    } while (numberOfNumbers <= 1);

    vector<int> numbers(numberOfNumbers);
    for (int i = 0; i < numbers.size(); i++) {
        cout << "Enter number " << i + 1 << ":" << endl;
        cin >> numbers[i];
        cout << "Number " << i + 1 << " is now " << numbers[i] << endl;
    }
    cout << "The sum of the numbers you entered is " << sum(numbers) << endl;
    cout << "The average of the numbers you entered is " << average(numbers) << endl;
    cout << "The largest number of the numbers you entered is " << largest(numbers) << endl;
    cout << "The smallest number of the numbers you entered is " << smallest(numbers) << endl;
    int evens, odds;
    tie(evens, odds) = evensAndOdds(numbers);
    cout << "The number of even numbers out of the numbers you entered is " << evens << endl;
    cout << "The number of odds numbers out of the numbers you entered is " << odds << endl;
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

static int sum(vector<int> numbers) {
    int sum = 0;
    for (int number : numbers) {
        sum += number;
    }
    return sum;
}

static float average(vector<int> numbers) {
    int sum = 0;
    for (int number : numbers) {
        sum += number;
    }
    return sum /(float)numbers.size();
}

static int largest(vector<int> numbers) {
    int largest = numbers[0];
    for (int number : numbers) {
        if (number > largest) {
            largest = number;
        }
    }
    return largest;
}

static int smallest(vector<int> numbers) {
    int smallest = numbers[0];
    for (int number : numbers) {
        if (number < smallest) {
            smallest = number;
        }
    }
    return smallest;
}

static tuple<int, int> evensAndOdds(vector<int> numbers) {
    int evens = 0;
    int odds = 0;
    for (int number : numbers) {
        if (number % 2 == 0) {
            evens++;
        }
        else if (number % 2 == 1) {
            odds++;
        }
    }
    return make_tuple(evens, odds);
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
