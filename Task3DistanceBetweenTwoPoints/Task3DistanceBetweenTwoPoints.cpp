// Task3DistanceBetweenTwoPoints.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double x1;
	double x2;
	double y1;
	double y2;
	cout << "We are going to calculate the distance between 2 points." << endl;
	cout << "Enter the x axis for point 1: ";
	cin >> x1;
	cout << "Enter the xy axis for point 1: ";
	cin >> y1;
	cout << "The coordinates of point 1 are : (" << x1 << ", " << y1 << ")" << endl;
	cout << "Enter the x axis for point 2: ";
	cin >> x2;
	cout << "Enter the xy axis for point 2: ";
	cin >> y2;
	cout << "The coordinates of point 2 are : (" << x2 << ", " << y2 << ")" << endl;
	double distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	cout << " the distance between the points (" << x1 << ", " << y1 << ")" << " and (" << x2 << ", " << y2 << ")" << " is " << distance << endl;
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
