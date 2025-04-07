// Week4Task4MazeLoader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream> // for file streams
#include <string>
#include <array>
#include <tuple>
#include <conio.h>

using namespace std;
struct Maze
{
    array<array<char, 16>, 11> maze;
    tuple<int, int> start;
    tuple<int, int> end;
    tuple<int, int> location;
    
};
Maze uploadMaze(string fileName);
static void displayMaze(Maze& maze);
static void solveMaze(Maze& maze);
int main()
{
    Maze maze = uploadMaze("maze.txt");
    displayMaze(maze);
    solveMaze(maze);
}

Maze uploadMaze(string fileName) 
{
    ifstream inFile(fileName);
    char mazeChar;
    string mazeRow;
    Maze maze;

    if (inFile.is_open()) 
    {
        int row = 0;
        for (string mazeRow; getline(inFile, mazeRow);)
        {
            int column = 0;
            for (char mazeChar : mazeRow) {
                // Process each character 'c' in the line
                maze.maze[row][column] = mazeChar;
                if (mazeChar == 'S') {
                    maze.start = make_tuple(row, column);
                    maze.location = make_tuple(row, column);
                }
                else if (mazeChar == 'E') {
                    maze.end = make_tuple(row, column);
                }
                if (++column == 16) {
                    break;
                }
            }
            if (++row == 11) {
                break;
            }
        }
    }
    inFile.close();
    return maze;
}
static void displayMaze(Maze& maze) 
{
    for (int i = 0; i < maze.maze.size(); i++) 
    {
        for (int j = 0; j < maze.maze[0].size(); j++) 
        {
            cout << maze.maze[i][j];
        }
        cout << endl;
    }
}
static void solveMaze(Maze& maze)
{
    int row, column;
    tie(row, column) = maze.location;
    while (!(maze.maze[row][column + 1] == 'E' || maze.maze[row + 1][column] == 'E' ||
        maze.maze[row - 1][column] == 'E' || maze.maze[row][column - 1] == 'E')) 
    {
        if (maze.maze[row][column + 1] == ' ')
        {
            if (tie(maze.location) == tie(maze.start))
            {
                maze.maze[row][++column] = 'P';
                maze.location = make_tuple(row, column);
            }
            else
            {
                maze.maze[row][column++] = '_';
                maze.maze[row][column] = 'P';
                maze.location = make_tuple(row, column);
            }
        }
        else if (maze.maze[row + 1][column] == ' ')
        {
            if (tie(maze.location) == tie(maze.start))
            {
                maze.maze[++row][column] = 'P';
                maze.location = make_tuple(row, column);
            }
            else
            {
                maze.maze[row++][column] = '|';
                maze.maze[row][column] = 'P';
                maze.location = make_tuple(row, column);
            }
        }
        else if (maze.maze[row - 1][column] == ' ')
        {
            if (tie(maze.location) == tie(maze.start))
            {
                maze.maze[--row][column] = 'P';
                maze.location = make_tuple(row, column);
            }
            else
            {
                maze.maze[row--][column] = '|';
                maze.maze[row][column] = 'P';
                maze.location = make_tuple(row, column);
            }
        }
        else if (maze.maze[row][column - 1] == ' ')
        {
            if (tie(maze.location) == tie(maze.start))
            {
                maze.maze[row][--column] = 'P';
                maze.location = make_tuple(row, column);
            }
            else
            {
                maze.maze[row][column--] = '_';
                maze.maze[row][column] = 'P';
                maze.location = make_tuple(row, column);
            }
        }
        else  if (maze.maze[row][column - 1] == '_')
        {
            maze.maze[row][column--] = '-';
            maze.maze[row][column] = 'P';
            maze.location = make_tuple(row, column);
        }
        else if (maze.maze[row - 1][column] == '|')
        {
            maze.maze[row--][column] = '/';
            maze.maze[row][column] = 'P';
            maze.location = make_tuple(row, column);
        }
        else if (maze.maze[row + 1][column] == '|')
        {
            maze.maze[row++][column] = '/';
            maze.maze[row][column] = 'P';
            maze.location = make_tuple(row, column);
        }
        else if (maze.maze[row][column + 1] == '_')
        {
            maze.maze[row][column++] = '-';
            maze.maze[row][column] = 'P';
            maze.location = make_tuple(row, column);
        }

        if (maze.maze[row][column + 1] == 'E' || maze.maze[row + 1][column] == 'E' ||
            maze.maze[row - 1][column] == 'E' || maze.maze[row][column - 1] == 'E')
        {
            cout << "You have won!" << endl;
            return;
        }
        cout << "Press any key to continue..." << std::endl;
        _getch();
        cout << "Key pressed. Program continues." << std::endl;
        printf("\033c");
        displayMaze(maze);
    }
}
// if another space in the same array is blank go forward replace with _
// if forward is full if there is a blank space down jump down an array and replace with |
// if down is full retrace until you get another option to have a blank space replace horizontal with - or vertical with \
// keep going until you find E
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
