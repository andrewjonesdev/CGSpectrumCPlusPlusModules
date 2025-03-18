// Week2Task3AdventureGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	// Variables
	int operationChoice = 0;
	do {

		do {
			// Ask the user which operation they would like to perform
			cout << "You reach a fork in the road, do you go:\n";
			cout << "1. North - To the forest\n";
			cout << "2. East - To the mines\n";
			cout << "3. South - To the desert\n";
			cout << "4. West - To the city\n\n";

			cout << "You entered: ";
			cin >> operationChoice;

			if (!(operationChoice >= 1 && operationChoice <= 4))
				cout << operationChoice << " is not one of the 4 choices. Please try again: ";
		} while (!(operationChoice >= 1 && operationChoice <= 4));
		// Perform the selected operation
		switch (operationChoice)
		{
		case 1: // Forest
		{
			do {
				// Ask the user which operation they would like to perform
				cout << "You see a sword in the stone, what will you do:\n";
				cout << "1. Pull it out\n";
				cout << "2. Walk on by\n";


				cout << "You entered: ";
				cin >> operationChoice;

				if (!(operationChoice >= 1 && operationChoice <= 2))
					cout << operationChoice << " is not one of the 2 choices. Please try again: ";
			} while (!(operationChoice >= 1 && operationChoice <= 2));
			switch (operationChoice)
			{
			case 1: // Grab the Sword
			{
				cout << "You grab the sword from the stone and are proclaimed the king of all the lands! YOU WIN.\n";
				break;
			}
			case 2: // Move On
			{

				do {
					cout << "You move on but run into angry elves. What will you do!\n";
					cout << "1. Fight!\n";
					cout << "2. Throw a smoke bomb\n";
					cout << "3. Try to negotiate\n";
					cout << "4. Flee!\n\n";

					cout << "You entered: ";
					cin >> operationChoice;

					if (!(operationChoice >= 1 && operationChoice <= 4))
						cout << operationChoice << " is not one of the 4 choices. Please try again: ";
				} while (!(operationChoice >= 1 && operationChoice <= 4));

				// Perform the selected operation
				switch (operationChoice)
				{
				case 1: // Fight
				{
					cout << "They gang up on you, beat you, and imprison you in the dungeon! GAME OVER.\n";
					break;
				}
				case 2: // Smoke Bomb
				{
					do {
						// Ask the user which operation they would like to perform
						cout << "The elves are blinded and you have the upper hand! What will you do!\n";
						cout << "1. Fight!\n";
						cout << "2. Flee\n";

						cout << "You entered: ";
						cin >> operationChoice;
						if (!(operationChoice >= 1 && operationChoice <= 2))
							cout << operationChoice << " is not one of the 2 choices. Please try again: ";
					} while (!(operationChoice >= 1 && operationChoice <= 2));
					switch (operationChoice)
					{
					case 1: // Fight
					{
						cout << "You defeat the elves and become their king YOU WIN.\n";
						break;
					}
					case 2: // Escape
					{

						cout << "You escaped and made it to the other side of the forest. You are out of stamina. Come back in 24 hours to continue!\n";
						break;
					}
					default:
					{
						cout << operationChoice << " is not one of the 2 choices. Please try again: ";
					}
					}
					break;
				}
				case 3: // Negotiate
				{
					cout << "You can’t talk your way out of this one, your attackers imprison you in the dungeon! GAME OVER.\n";
					break;
				}
				case 4: // Flee
				{
					cout << "They catch you and your attackers imprison you in the dungeon! GAME OVER.\n";
					break;
				}
				default:
				{
					cout << operationChoice << " is not one of the 4 choices. Please try again: ";
				}
				}
				break;
			}
			default:
			{
				cout << operationChoice << " is not one of the 2 choices. Please try again: ";
			}
			}
			break;
		}

		case 2: // Mines
		{
			do {
				// Ask the user which operation they would like to perform
				cout << "You see a glimmer of light deep in the mines! What will you do.\n";
				cout << "1. Investigate!\n";
				cout << "2. Move on\n";

				cout << "You entered: ";
				cin >> operationChoice;

				if (!(operationChoice >= 1 && operationChoice <= 2))
					cout << operationChoice << " is not one of the 2 choices. Please try again: ";
			} while (!(operationChoice >= 1 && operationChoice <= 2));
			switch (operationChoice)
			{
			case 1: // Investigate
			{
				cout << "You find a great treasure of precious minerals! YOU WIN.\n";
				break;
			}
			case 2: // Move On
			{
				do {
					cout << "You move on but run into scavengers. What will you do!\n";
					cout << "1. Fight!\n";
					cout << "2. Throw a smoke bomb\n";
					cout << "3. Try to negotiate\n";
					cout << "4. Flee!\n\n";

					cout << "You entered: ";
					cin >> operationChoice;

					if (!(operationChoice >= 1 && operationChoice <= 4))
						cout << operationChoice << " is not one of the 4 choices. Please try again: ";
				} while (!(operationChoice >= 1 && operationChoice <= 4));

				// Perform the selected operation
				switch (operationChoice)
				{
				case 1: // Fight
				{
					cout << "They gang up on you, beat you, and harvest your organs! GAME OVER.\n";
					break;
				}
				case 2: // Smoke Bomb
				{
					do {
						// Ask the user which operation they would like to perform
						cout << "The scavengers are blinded and you have the upper hand! What will you do!\n";
						cout << "1. Fight!\n";
						cout << "2. Flee\n";

						cout << "You entered: ";
						cin >> operationChoice;
						switch (operationChoice)
						{
						case 1: // Fight
						{
							cout << "You defeat the scavengers and take all their belongings! YOU WIN.\n";
							break;
						}
						case 2: // Escape
						{

							cout << "You escaped and made it to the other side of the city. You are out of stamina. Come back in 24 hours to continue!\n";
							break;
						}
						default:
						{
							cout << operationChoice << " is not one of the 2 choices. Please try again: ";
						}
						}
					} while (!(operationChoice >= 1 && operationChoice <= 2));
					break;
				}
				case 3: // Negotiate
				{
					cout << "You can’t talk your way out of this one, your attackers harvest your organs! GAME OVER.\n";
					break;
				}
				case 4: // Flee
				{
					cout << "They catch you and your attackers harvest your organs! GAME OVER.\n";
					break;
				}
				default:
				{
					cout << operationChoice << " is not one of the 4 choices. Please try again: ";
				}
				}
				break;
			}
			}
			break;
		}
		case 3: // Desert
		{
			cout << "You die of starvation! GAME OVER.\n";
			break;
		}
		case 4: // City
		{
			do {
				// Ask the user which operation they would like to perform
				cout << "As you stroll through the alleyways of the city you are attacked by bandits! What do you do?\n";
				cout << "1. Fight!\n";
				cout << "2. Throw a smoke bomb\n";
				cout << "3. Try to negotiate\n";
				cout << "4. Flee!\n\n";

				cout << "You entered: ";
				cin >> operationChoice;

				if (!(operationChoice >= 1 && operationChoice <= 4))
					cout << operationChoice << " is not one of the 4 choices. Please try again: ";
			} while (!(operationChoice >= 1 && operationChoice <= 4));
			// Perform the selected operation
			switch (operationChoice)
			{
			case 1: // Fight
			{
				cout << "They gang up on you, beat you, and take all your belongings! GAME OVER.\n";
				break;
			}
			case 2: // Smoke Bomb
			{
				do {
					// Ask the user which operation they would like to perform
					cout << "The bandits are blinded and you have the upper hand! What will you do!\n";
					cout << "1. Fight!\n";
					cout << "2. Flee\n";

					cout << "You entered: ";
					cin >> operationChoice;

					if (!(operationChoice >= 1 && operationChoice <= 2))
						cout << operationChoice << " is not one of the 2 choices. Please try again: ";
				} while (!(operationChoice >= 1 && operationChoice <= 2));
				switch (operationChoice)
				{
				case 1: // Fight
				{
					cout << "You defeat the bandits and take all their belongings! YOU WIN.\n";
					break;
				}
				case 2: // Escape
				{

					cout << "You escaped and made it to the other side of the city. You are out of stamina. Come back in 24 hours to continue!\n";
					break;
				}
				default:
				{
					cout << operationChoice << " is not one of the 2 choices. Please try again: ";
				}
				}
				break;
			}
			case 3: // Negotiate
			{
				cout << "You can’t talk your way out of this one, your attackers take all your belongings! GAME OVER.\n";
				break;
			}
			case 4: // Flee
			{
				cout << "They catch you and your attackers take all your belongings! GAME OVER.\n";
				break;
			}
			default:
			{
				cout << operationChoice << " is not one of the 4 choices. Please try again: ";
			}
			}
			break;
		}
		default:
		{
			cout << operationChoice << " is not one of the 4 choices. Please try again: ";
		}
		}
		do {
			cout << "\n" << endl;
			cout << "Do you want to play again: ";
			cout << "1. Yes\n";
			cout << "2. No\n";
			cout << "You entered: ";
			cin >> operationChoice;
			if (!(operationChoice >= 1 && operationChoice <= 4))
				cout << operationChoice << " is not one of the 4 choices. Please try again: ";
			cout << "\n" << endl;
		} while (!(operationChoice == 1 || operationChoice == 2));
	} while (operationChoice == 1);

	cout << endl;
	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menuhh
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
