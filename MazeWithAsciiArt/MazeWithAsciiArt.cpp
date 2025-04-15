// Week4Task4MazeLoader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream> // for file streams
#include <string>
#include <array>
#include <tuple>
#include <conio.h>
#include <io.h>
#include <fcntl.h>
#include <Windows.h>
using namespace std;

using namespace std;
struct Maze
{
    array<array<char, 16>, 11> maze;
    tuple<int, int> start;
    tuple<int, int> end;
    tuple<int, int> location;
};
struct MapArt
{
    array<array<wchar_t, 47>, 26> player;
    array<array<wchar_t, 47>, 26> emptySpace;
    array<array<wchar_t, 47>, 26> block;
    array<array<wchar_t, 47>, 26> start;
    array<array<wchar_t, 47>, 26> end;
    array<array<wchar_t, 752>, 528> map;

};
static void makePlayer(MapArt& map);
static void makeMapArt(MapArt& map);
Maze uploadMaze(string fileName);
static void displayMaze(Maze& maze);
static void makeMazeAscii(Maze& maze, MapArt& map);
static void displayMazeAscii(MapArt& map);
static void solveMaze(Maze& maze, MapArt& map);
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    std::wcout.imbue(locale::global(locale("en_US.UTF-8")));
    Maze maze = uploadMaze("maze.txt");
    MapArt map = MapArt();
    makePlayer(map);
    makeMapArt(map);
    makeMazeAscii(maze, map);
    displayMazeAscii(map);
    solveMaze(maze, map);
}

static void makePlayer(MapArt& map)
{
    wstring asciiPlayer = L"";
    asciiPlayer += L"── ── ── ── ── ── ── ██ ██ ██ ██ ── ██ ██ ██ ──";
    asciiPlayer += L"── ── ── ── ── ██ ██ ▓▓ ▓▓ ▓▓ ██ ██ ░░ ░░ ░░ ██";
    asciiPlayer += L"── ── ── ── ██ ▓▓ ▓▓ ▓▓ ▓▓ ▓▓ ▓▓ ██ ░░ ░░ ░░ ██";
    asciiPlayer += L"── ── ── ██ ▓▓ ▓▓ ▓▓ ██ ██ ██ ██ ██ ██ ░░ ░░ ██";
    asciiPlayer += L"── ── ██ ▓▓ ▓▓ ▓▓ ██ ██ ██ ██ ██ ██ ██ ██ ░░ ██";
    asciiPlayer += L"── ── ██ ▓▓ ██ ██ ░░ ░░ ░░ ░░ ░░ ░░ ██ ██ ██ ──";
    asciiPlayer += L"── ██ ██ ██ ██ ░░ ░░ ░░ ██ ░░ ██ ░░ ██ ▓▓ ▓▓ ██";
    asciiPlayer += L"── ██ ░░ ██ ██ ░░ ░░ ░░ ██ ░░ ██ ░░ ██ ▓▓ ▓▓ ██";
    asciiPlayer += L"██ ░░ ░░ ██ ██ ██ ░░ ░░ ░░ ░░ ░░ ░░ ░░ ██ ▓▓ ██";
    asciiPlayer += L"██ ░░ ░░ ░░ ██ ░░ ░░ ██ ░░ ░░ ░░ ░░ ░░ ██ ▓▓ ██";
    asciiPlayer += L"── ██ ░░ ░░ ░░ ░░ ██ ██ ██ ██ ░░ ░░ ██ ██ ██ ──";
    asciiPlayer += L"── ── ██ ██ ░░ ░░ ░░ ░░ ██ ██ ██ ██ ██ ▓▓ ██ ──";
    asciiPlayer += L"── ── ── ██ ██ ██ ░░ ░░ ░░ ░░ ░░ ██ ▓▓ ▓▓ ██ ──";
    asciiPlayer += L"── ░░ ██ ▓▓ ▓▓ ██ ██ ██ ██ ██ ██ ██ ▓▓ ██ ── ──";
    asciiPlayer += L"── ██ ▓▓ ▓▓ ▓▓ ▓▓ ██ ██ ░░ ░░ ░░ ██ ██ ── ── ──";
    asciiPlayer += L"██ ██ ▓▓ ▓▓ ▓▓ ▓▓ ██ ░░ ░░ ░░ ░░ ░░ ██ ── ── ──";
    asciiPlayer += L"██ ██ ▓▓ ▓▓ ▓▓ ▓▓ ██ ░░ ░░ ░░ ░░ ░░ ██ ── ── ──";
    asciiPlayer += L"██ ██ ██ ▓▓ ▓▓ ▓▓ ▓▓ ██ ░░ ░░ ░░ ██ ██ ██ ██ ──";
    asciiPlayer += L"── ██ ██ ██ ▓▓ ▓▓ ▓▓ ██ ██ ██ ██ ██ ██ ██ ██ ──";
    asciiPlayer += L"── ── ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ▓▓ ▓▓ ██";
    asciiPlayer += L"── ██ ▓▓ ▓▓ ██ ██ ██ ██ ██ ██ ██ ██ ▓▓ ▓▓ ▓▓ ██";
    asciiPlayer += L"██ ██ ▓▓ ██ ██ ██ ██ ██ ██ ██ ██ ██ ▓▓ ▓▓ ▓▓ ██";
    asciiPlayer += L"██ ▓▓ ▓▓ ██ ██ ██ ██ ██ ██ ██ ██ ██ ▓▓ ▓▓ ▓▓ ██";
    asciiPlayer += L"██ ▓▓ ▓▓ ██ ██ ██ ██ ██ ── ── ── ██ ▓▓ ▓▓ ██ ██";
    asciiPlayer += L"██ ▓▓ ▓▓ ██ ██ ── ── ── ── ── ── ── ██ ██ ██ ──";
    asciiPlayer += L"── ██ ██ ── ── ── ── ── ── ── ── ── ── ── ── ──";
    wcout << asciiPlayer.length() <<endl;
    int letterCount = 0;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 47; j++)
        {
            map.player[i][j] = asciiPlayer[letterCount++];
            //wcout << map.player[i][j];
        }
        //wcout << letterCount << endl;
        //wcout << endl;
    }
}
static void makeMapArt(MapArt& map)
{
    int letterCount = 0;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 47; j++)
        {
            map.block[i][j] = L'█';
        }
    }
    letterCount = 0;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 47; j++)
        {
            map.emptySpace[i][j] = ' ';
        }
    }
    letterCount = 0;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 47; j++)
        {
            map.start[i][j] = L'_';
        }
    }
    letterCount = 0;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 47; j++)
        {
            map.end[i][j] = L'|';
        }
    }
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
                if (mazeChar == L'S') {
                    maze.start = make_tuple(row, column);
                    maze.location = make_tuple(row, column);
                }
                else if (mazeChar == L'E') {
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
            wcout << maze.maze[i][j];
        }
        wcout << endl;
    }
}

static void displayMazeAscii(MapArt& map)
{
    for (int i = 0; i < map.map.size(); i++)
    {
        for (int j = 0; j < map.map[0].size(); j++)
        {
            wcout << map.map[i][j];
        }
        wcout << endl;
    }
}
static void makeMazeAscii(Maze& maze, MapArt& map)
{
    int ii = 0;
    int jj = 0;
    for (int i = 0; i < maze.maze.size(); i++)
    {
        wcout << "i: " << i << endl;
        for (int j = 0; j < maze.maze[0].size(); j++)
        {
            wcout << "j: " << j << endl;
            if (maze.maze[i][j] == L'*')
            {
                for (ii = i == 0 ? 0 : ((i * 26) - 1); ii < (((i * 26) + 26) - 1); ii++)
                {
                    for (jj = j == 0 ? 0 : ((j * 47) - 1); jj < (((j * 47) + 47) - 1); jj++)
                    {
                        if (i == 0 || j == 0)
                        {
                            map.map[ii][jj] = map.block[i][j];
                        }
                        else
                        {
                            map.map[ii][jj] = map.block[ii % i][jj % j];
                        }
                        wcout << "Bjj: " << jj << endl;
                    }
                    wcout << "Bii: " << ii << endl;
                }
            }else if (maze.maze[i][j] == L'S') 
            {
                for (ii = i == 0 ? 0 : ((i * 26) - 1); ii < (((i * 26) + 26) - 1); ii++)
                {
                    for (jj = j == 0 ? 0 : ((j * 47) - 1); jj < (((j * 47) + 47) - 1); jj++)
                    {
                        if (i == 0 || j == 0) 
                        {
                            map.map[ii][jj] = map.start[i][j];
                        }
                        else
                        {
                            map.map[ii][jj] = map.start[ii % i][jj % j];
                        }
                        wcout << "Sjj: " << jj << endl;
                    }
                    wcout << "Sii: " << ii << endl;
                }
            }else if (maze.maze[i][j] == L'P') 
            {
                for (ii = i == 0 ? 0 : ((i * 26) - 1); ii < (((i * 26) + 26) - 1); ii++)
                {
                    for (jj = j == 0 ? 0 : ((j * 47) - 1); jj < (((j * 47) + 47) - 1); jj++)
                    {
                        if (i == 0 || j == 0) 
                        {
                            map.map[ii][jj] = map.player[i][j];
                        }
                        else
                        {
                            map.map[ii][jj] = map.player[ii % i][jj % j];
                        }
                        wcout << "Pjj: " << jj << endl;
                    }
                    wcout << "Pii: " << ii << endl;
                }
            }else if (maze.maze[i][j] == L'E') 
            {
                for (ii = i == 0 ? 0 : ((i * 26) - 1); ii < (((i * 26) + 26) - 1); ii++)
                {
                    for (jj = j == 0 ? 0 : ((j * 47) - 1); jj < (((j * 47) + 47) - 1); jj++)
                    {
                        if (i == 0 || j == 0) 
                        {
                            map.map[ii][jj] = map.end[i][j];
                        }
                        else
                        {
                            map.map[ii][jj] = map.end[ii % i][jj % j];
                        }
                        wcout << "Ejj: " << jj << endl;
                    }
                    wcout << "Eii: " << ii << endl;
                }
            }else 
            {
                for (ii = i == 0 ? 0 : ((i * 26) - 1); ii < (((i * 26) + 26) - 1); ii++)
                {
                    for (jj = j == 0 ? 0 : ((j * 47) - 1); jj < (((j * 47) + 47) - 1); jj++)
                    {
                        if (i == 0 || j == 0) 
                        {
                            map.map[ii][jj] = map.emptySpace[ii][jj];
                        }else
                        {
                            map.map[ii][jj] = map.emptySpace[ii % i][jj % j];
                        }
                        wcout << "Ojj: " << jj << endl;
                    }
                    wcout << "Oii: " << ii << endl;
                }
            }
        }
    }
}
static void solveMaze(Maze& maze, MapArt& map)
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
            wcout << "You have won!" << endl;
            return;
        }
        wcout << "Press any key to continue..." << std::endl;
        _getch();
        wcout << "Key pressed. Program continues." << std::endl;
        printf("\033c");
        displayMazeAscii(map);
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
