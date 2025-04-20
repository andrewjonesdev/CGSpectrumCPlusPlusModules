// Week5Task3SortAVector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;
static int randomNumber(int min, int max);
int main()
{
    int operationChoice = 0;
    do {
    int size = 0;
    vector<int> atLeastTen(randomNumber(10, 100));
    int order;
    for (int i = 0; i < atLeastTen.size(); i++) {
        atLeastTen[i] = randomNumber(1, 100);
    }
    do{
    cout << "Do you want to sort in ascending or descending order?\n";
    cout << "1. ascending\n";
    cout << "2. descending\n";

    cout << "You entered: ";
    cin >> order;

    if (!(order >= 1 && order <= 2))
        cout << order << " is not one of the 2 choices. Please try again: ";
    } while (!(order >= 1 && order <= 2));
    
    for (int pass = atLeastTen.size() - 1; pass >= 0; pass--)
    {
        for (int i = 0; i < pass; i++)
        {
            if (order == 1 ? atLeastTen[i] > atLeastTen[i + 1] : atLeastTen[i] < atLeastTen[i + 1])
            {
                int temp = atLeastTen[i];
                atLeastTen[i] =atLeastTen[i + 1];
                atLeastTen[i + 1] = temp;
            }
        }
    }
    for (int i = 0; i < atLeastTen.size(); i++)
    {
        cout << "{" << atLeastTen[i] << "}";
    }
    cout << endl;
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
static int randomNumber(int min, int max) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine engine(seed);
    uniform_int_distribution<int> distribution(min, max);
    return distribution(engine);
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
