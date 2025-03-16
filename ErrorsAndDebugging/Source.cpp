#include <iostream>

int main()
{
	// Variables
	int firstNumber = 0;
	int secondNumber = 0;
	int operationChoice = 0;
	int result = 0;

	// Ask the user to enter two numbers
	do {
		std::cout << "Enter a first whole number (1-10): ";
		std::cin >> firstNumber;
		if (!(firstNumber >= 1 && firstNumber <= 10)) {  // Fix 7: Handled logic in case it isn't a whole number between 1 and 10

			std::cout << firstNumber << " is not a whole number between 1-10. Please try again: ";
		}
	} while (!(firstNumber >= 1 && firstNumber <= 10));  // Fix 7: Handled logic in case it isn't a whole number between 1 and 10

	do {
		std::cout << "\nEnter a second whole number (1-10): ";
		std::cin >> secondNumber; // Fix 3: Logic: secondNumber should take the input here not firstNumber this will allow line 18 to execute
		if (!(secondNumber >= 1 && secondNumber <= 10)) {  // Fix 7: Handled logic in case it isn't a whole number between 1 and 10

			std::cout << secondNumber << " is not a whole number between 1-10. Please try again: ";
		}
	} while (!(secondNumber >= 1 && secondNumber <= 10)); // Fix 7: Handled logic in case it isn't a whole number between 1 and 10

	if (firstNumber >= 1 && firstNumber <= 10
		&& secondNumber >= 1 && secondNumber <= 10) // Fix 6: Logic: now numbers will be allowed to be 10
	{
		do {
		// Ask the user which operation they would like to perform
		std::cout << "Select an operation to perform on the two numbers:\n";
		std::cout << "1. Addition\n";
		std::cout << "2. Subtraction\n"; // Fix 5: Logic: \n wasn't there to create new line between 2 and 3
		std::cout << "3. Multiplcation\n";
		std::cout << "4. Division\n\n";

		std::cout << "User entered: ";
		std::cin >> operationChoice; // Fix 1: Compiler: added std:: before cin

		// Perform the selected operation
			switch (operationChoice)
			{
				case 1: // Addition
				{
					result = firstNumber + secondNumber;
					break; // Fix 4: Logic: was missing break so case 1 wouldn't be overriden with case 2
				}
				case 2: // Subtraction
				{
					result = firstNumber - secondNumber;
					break;
				}
				case 3: // Multiplication
				{
					result = firstNumber * secondNumber;
					break;
				}
				case 4: // Division
				{
					result = firstNumber / secondNumber; // Fix 7: By forcing the numbers to be between 1 and 10 the division by 0 runtime error is no longer able to happen
					break;
				}
				default: 
				{
					std::cout << operationChoice << " is not one of the 4 choices. Please try again: ";
				}
			}
		} while (!(operationChoice >= 1 && operationChoice <= 4)); // Fix 8: Handled logic in case it isn't a valid choice between 1-4

		// Print out the result of the division
		std::cout << "\nThe result is: " << result << "\n\n"; // Fix 2: Compiler: lowercased Result to result to match variable name
	}

	return 0;
}