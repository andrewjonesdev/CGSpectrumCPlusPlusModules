// Week4Task3AlphabetLoader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream> // for file streams
#include <ctime>
using namespace std;
int main()
{
    ifstream inFile("alphabet.txt");
    char letter;
    int i = 0;

    if (inFile.is_open()) {
        time_t timestamp = time(NULL);
        struct tm timestampDT;
        localtime_s(&timestampDT, &timestamp);
        time(&timestamp);
        char dateTime[50];
        strftime(dateTime, 50, "%b-%d-%Y-%H-%M-%S", &timestampDT);
        string dateTimeStr = dateTime;
        cout << dateTimeStr << endl;
        dateTimeStr = dateTimeStr.erase(dateTimeStr.find_last_not_of(" \n\r\t") + 1);
        cout << dateTimeStr << endl;
        dateTimeStr = dateTimeStr.erase(0, dateTimeStr.find_first_not_of(" \n\r\t"));
        cout << dateTimeStr << endl;
        string fileName = ("alphabet_" + dateTimeStr + ".txt");
        cout << fileName << endl;
        ofstream outFile(fileName);
        if (outFile.is_open()) {
        while (inFile >> letter) {
            cout << "Started as:  " << letter << endl;
            letter -= 32;
            cout << "Finished as:  " << letter << endl;
                // write some ints to the file
                outFile << letter << endl;
                // close file after writing

                cout << ++i << ") " << letter << " was written to the file successfully." << endl;
            }
        }
        cout << "All letters were written to the file successfully." << endl;

        outFile.close();
        inFile.close();
    }
    else {
        cout << "Error opening file for reading." << endl;
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
