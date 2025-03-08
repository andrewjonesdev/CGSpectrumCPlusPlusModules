// CGSpectrumWeek2CPlusPlus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    // dataType variableName;
    int age;
    float weight;
    double distance;
    bool isAlive;
    char initial;
    // std is namespace 
    //std::string name;
    string name;

    unsigned short int betterAge;
    long double hugeDistance;

    age = 30;
    weight = 190.5f;
    distance = 1212.987;
    isAlive = true;
    initial = 'F';
    name = "Filip";

    //std::cout << "My name is " << name << std::endl;
    cout << "My name is " << name << " and I am " << age << " years old." << endl;
    cout << "Am I alive: " << isAlive << endl;

    int newAge;
    newAge = age; // 30

    int newestAge = 25;

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
