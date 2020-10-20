#include <iostream>
#include <conio.h>
#include <vector>
#include "Mock Exam.h"
#include <time.h>


int main()
{
	srand(time(NULL));
	Login login;
	int failCounter = 0;

	RETRY:
	bool attempt = login.LoginAttempt();
	
	if (!attempt && failCounter < 2)
	{
		failCounter++;
		std::cout << "\n Wrong Password! You have " << 3 - failCounter << " more attempt(s)\n ";
		system("pause");
		goto RETRY;
	}
	else if (attempt)
	{
		MainMenu();
	}
	std::cout << "You have failed to login, exiting the application. \n\n";
	return 0;
}

void MainMenu()
{
	do
	{
		system("CLS");
		std::cout << "--- [ Main Menu ] ---\n";
		std::cout << "Select a task : \n";
		std::cout << " 1. Task 1\n" << " 2. Task 2\n" << " 3. Task 3\n" << " 4. Task 4\n" << "\n 5. Exit Application\n";

		int input;
		std::cin >> input;
		switch (input)
		{
		case 1 :
			Task1();
			break;
		case 2 : 
			Task2();
			break;
		case 3 :
			Task3();
			break;
		case 4 : 
			//i call task 3 here because they are quite similar, and it goes as one. 
			Task3();
			break;
		case 5 : 
			std::cout << "Exiting the application!\n\n";
			exit(0);
			break;
		default:
		//I use the RETRY and Goto in the case where they don't respond with either of the options
			RETRY:
			std::cin.clear();
			std::cin.ignore(8000, '\n');
			std::cout << "Wrong input ... Do you want to try again? (y/n) : ";
			char answer;
			std::cin >> answer;
			answer = tolower(answer);
			if (answer == 'y')
			{
				continue;
			}
			else if (answer == 'n')
			{
				std::cout << "Okay! Exiting the exiting the application!\n";
				exit(0);
			}
			else
			{
				goto RETRY;
			}
			break;
		}


	} while (true);
}

void Task1()
{
	system("CLS");
	int throwIterations = 2000;
	int DiceOutput[6]{ 0,0,0,0,0,0 };

	for (int i = 0; i < throwIterations; i++)
	{
		++DiceOutput[RollDice()];
	}
	std::cout << " A dice was rolled a total of " << throwIterations << " times and these are the results : \n";
	for (int i = 0; i < 6; i++)
	{
		std::cout << i+1 << ": " << DiceOutput[i] << " times.\n";
	}
	system("pause");
	MainMenu();
}
void Task2()
{
	system("CLS");
	int iterations = 20;
	std::vector<Thing> things{};
	for (int i = 0; i < iterations; i++)
	{
		Thing th;
		th.index = i;
		things.push_back(th);
	}
	
	std::cout << " --- [ Before Sort ] --- \n";
	PrintVector(things);
	
	std::cout << "\n\n --- [ After Sort ] --- \n";
	VectorSort(things);
	PrintVector(things);

	std::cout << std::endl;
	system("pause");
	MainMenu();
}
void VectorSort(std::vector<Thing>& _vect)
{
	std::sort(_vect.begin(), _vect.end(), CompareByStructValue);
}
void PrintVector(std::vector<Thing>& _vect)
{
	std::cout << " No \t Name \t Value \t Health Bar \n";
	std::cout << "--------------------------------------------------\n";
	for (auto x : _vect)
	{
		std::cout <<" "<< x.index << " \t " << x.name << " \t " << x.value << " \t " << x.healthBar << std::endl;
	}
}
void Task3()
{
	char grid[10][10] = {
						 {'|','#','#','#','#','#','#','#','#','|'},
						 {'|',' ',' ','.','.','.','.','.','.','|'},
						 {'|','#','#','.','#','#','#','#','#','|'},
						 {'|','.','.','.','.','.','.','.','.','|'},
						 {'|','.','|','.','|','#','#','#','|','|'},
						 {'|','.','|','.','|','.','.','.','|','|'},
						 {'|','.','|','.','.','.','.','.','.','|'},
						 {'|','.','.','.','.','.','.','.','.','|'},
						 {'|','.','.','#','#','#','#','#','.','|'},
						 {'|','#','#','#','#','#','#','#','#','|'},};
	
	int input;
	char playerChar = 'E';
	char previousChar = ' ';
	//Starting position
	int x = 1;
	int y = 1;
	int PlayerScore = 0;
	grid[x][y] = playerChar;
	DisplayGameGrid(grid);
	do
	{
		
		input = tolower(_getch());
		grid[x][y] = previousChar;
		switch (input)
		{
		case 'w':
			// These if statements are somewhat weird to look at,
			// because im checking for two different types of walls, 
			// I check if both of those are not a wall, and only when both are checked, i can move on.
			if ((grid[x - 1][y] != '#') && (grid[x - 1][y] != '|')) 
			{
				x--;
			}
			break;
		case 'a':
			if ((grid[x][y - 1] != '#') && (grid[x][y - 1] != '|'))
			{
				y--;
			}
			break;
		case 'd':
			if ((grid[x][y + 1] != '#') && (grid[x][y + 1] != '|'))
			{
				y++;
			}
			break;
		case 's':
			if ((grid[x+1][y] != '#') && (grid[x + 1][y] != '|'))
			{
				x++;
			}
			break;
		case 'e' :
			MainMenu();
			break;
		default:
			break;
		}

		previousChar = grid[x][y];
		//Checking for points
		if (previousChar == '.')
		{
			PlayerScore += 5;
			previousChar = ' ';
		}
		
		grid[x][y] = playerChar;
		DisplayGameGrid(grid);
		std::cout << "Score = " <<  PlayerScore;
	} while (PlayerScore < 200);
	std::cout << "\n\n Congratulations! You've won the game! \n";
	
	std::cout << "Do you want to play again? (y/n)";
RETRY:
	char answer;
	std::cin >> answer;
	answer = tolower(answer);
	if (answer == 'y')
	{
		Task3();
		return;
	}
	else if (answer == 'n')
	{
		MainMenu();
	}
	else
	{
		std::cin.clear();
		std::cin.ignore(8000, '\n');
		goto RETRY;
	}
}
void DisplayGameGrid(char grid[10][10])
{
	system("CLS");

	std::cout << "Objective : Collect all the . on the grid to finish!\n";
	std::cout << "Use WASD to move around. \n";
	std::cout << "If you want to exit to the main menu before finishing just hit the 'E' key\n\n";

	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			std::cout << grid[x][y] << " ";
		}
		std::cout << std::endl;
	}
}

