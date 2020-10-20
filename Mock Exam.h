#pragma once

//Getch method
#include <conio.h>

#include <vector>

//for the sorting of the vector
#include <algorithm>

void MainMenu();
void Task1();

void Task2();


void Task3();
// Login Task
struct Login {
private:
    char PasswordGrid[3][3];
    
	int x = 0, y = 0;
    //This is the password
	std::string pwLock{ "14523" };
    void SetupGrid()
    {
        //Ascii code for the number 1
        int count = 49;
        
        for (int y = 0; y < 3; y++)
        {
            for (int x = 0; x < 3; x++)
            {
                PasswordGrid[x][y] = count++;
            }
        }
    }

public:
    void DisplayGrid()
    {
        system("CLS");
        std::cout << "Please login with your shape : \n";
        for (int y = 0; y < 3; y++)
        {
            std::cout << " ";
            for (int x = 0; x < 3; x++)
            {
                std::cout << "| " << PasswordGrid[x][y] << " ";
            }
            std::cout << "|\n";
        }
    }
    
	bool LoginAttempt()
	{
        SetupGrid();
        char previousLocationChar = '1';
        char inputLocationChar = '*';

        std::string pwInput = "1";

        x = 0; y = x;

        PasswordGrid[x][y] = inputLocationChar;
        DisplayGrid();
        do
        {
            
            int inputKey = _getch();
            PasswordGrid[x][y] = previousLocationChar;
            inputKey = tolower(inputKey);

            switch (inputKey)
            {
            case 'w' :
                if (y - 1 >= 0)
                {
                    y--;
                }
                break;
            case 'a' :
                if (x - 1 >= 0)
                {
                    x--;
                }
                break;
            case 'd' : 
                if (x + 1 < 3)
                {
                    x++;
                }
                break;
            case 's' :
                if (y + 1 < 3)
                {
                    y++;
                }
                break;
            default:
                break;
            }
            previousLocationChar = PasswordGrid[x][y];
            PasswordGrid[x][y] = inputLocationChar;
            pwInput.push_back(previousLocationChar);
            
            DisplayGrid();

        } while (pwLock.length() != pwInput.length());

        if (pwLock == pwInput)
        {
            return true;
        }
        else
        {

            return false;
        }
	}
};

// Dice Task

int RollDice()
{
    return rand() % 6;
}

// Sort task (task 2)
struct Thing
{
    short index = 0;
    char name = ' ';
    short value = 0;
    int health = 0;
    std::string healthBar = "";
    Thing()
    {
        //A random letter between A and Z
        name = rand() % 25 + 65;
        value = rand() % 20 + 1;
        health = rand() % 20 + 1;
        for (int i = 0; i < health; i++)
        {
            healthBar.push_back('*');
        }
    }
};
//the e stands for element one and element two of that im comparing
bool CompareByStructValue(const Thing& eone, const Thing& etwo)
{
    return eone.value < etwo.value;
}

void VectorSort(std::vector<Thing>& _vect);
void PrintVector(std::vector<Thing>& _vect);

//Task 3 stuff 
void DisplayGameGrid(char _grid[10][10]);



