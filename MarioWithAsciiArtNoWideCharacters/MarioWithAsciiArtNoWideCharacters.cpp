// Week4Task4MazeLoader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream> // for file streams
#include <string>
#include <array>
#include <tuple>
#include <conio.h>
#include <io.h>
#include <windows.h>
#include <Wincon.h>

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
    array<array<char, 25>, 12> player;
    array<array<char, 25>, 12> emptySpace;
    array<array<char, 25>, 12> block;
    array<array<char, 25>, 12> start;
    array<array<char, 25>, 12> end;
    array<array<char, 400>, 132> map;

};
static void makePlayer(MapArt& map);
static void makeMapArt(MapArt& map);
Maze uploadMaze(string fileName);
static void displayMaze(Maze& maze);
static void makeMazeAscii(Maze& maze, MapArt& map);
static void displayMazeAscii(MapArt& map);
static void solveMaze(Maze& maze, MapArt& map);
static bool haveNotWon(Maze& maze, MapArt& map);
static bool canGoLeft(Maze& maze, MapArt& map);
static bool canGoDown(Maze& maze, MapArt& map);
static bool canGoUp(Maze& maze, MapArt& map);
static bool canGoRight(Maze& maze, MapArt& map);
static bool isAtStart(Maze& maze, MapArt& map);
static bool canGoBackRight(Maze& maze, MapArt& map);
static bool canGoBackUp(Maze& maze, MapArt& map);
static bool canGoBackDown(Maze& maze, MapArt& map);
static bool canGoBackLeft(Maze& maze, MapArt& map);
static bool haveWon(Maze& maze, MapArt& map);
int main()
{
    Maze maze = uploadMaze("maze.txt");
    MapArt map = MapArt();
    makePlayer(map);
    makeMapArt(map);
    makeMazeAscii(maze, map);
    displayMazeAscii(map);
    cout << "Press any key to continue..." << std::endl;
    _getch();
    cout << "Key pressed. Program continues." << std::endl;
    solveMaze(maze, map);
}

static void makePlayer(MapArt& map)
{
    char ascii01[] = "    ************         ";
    char ascii02[] = "    ####....#.           ";
    char ascii03[] = "  #..###.....##....      ";
    char ascii04[] = "  ###.......######       ";
    char ascii05[] = "     ...........         ";
    char ascii06[] = "    ## * #######         ";
    char ascii07[] = " #### * ******######     ";
    char ascii08[] = "...# * **.* * **.*###....";
    char ascii09[] = "....* * ********##.....  ";
    char ascii10[] = "....* * *******....      ";
    char ascii11[] = "  ####        ####       ";
    char ascii12[] = "######        ######     ";
    array<char*, 16> asciiPlayer = { ascii01, ascii02, ascii03, ascii04, ascii05, ascii06, ascii07, ascii08, ascii09, ascii10, ascii11, ascii12 };
    //cout << asciiPlayer.length() << endl;
    int letterCount = 0;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            map.player[i][j] = asciiPlayer[i][j];
            cout << map.player[i][j];
        }
        //cout << letterCount << endl;
        cout << endl;
    }
}
static void makeMapArt(MapArt& map)
{
    int letterCount = 0;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            map.block[i][j] = '#';
        }
    }
    letterCount = 0;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            map.emptySpace[i][j] = ' ';
        }
    }
    letterCount = 0;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            map.start[i][j] = '>';
        }
    }
    letterCount = 0;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            map.end[i][j] = '$';
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

static void displayMazeAscii(MapArt& map)
{
    //HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //CONSOLE_FONT_INFOEX fontInfo;
    //fontInfo.cbSize = sizeof(fontInfo);
    //GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
    //short oldWidth = fontInfo.dwFontSize.X;
    //short oldHeight = fontInfo.dwFontSize.Y;
    //fontInfo.dwFontSize.X = 8; // Width
    //fontInfo.dwFontSize.Y = 8; // Height
    //SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
    for (int i = 0; i < map.map.size(); i++)
    {
        for (int j = 0; j < map.map[0].size(); j++)
        {
            cout << map.map[i][j];
        }
        cout << endl;
    }
    //fontInfo.dwFontSize.X = oldWidth; // Width
    //fontInfo.dwFontSize.Y = oldHeight; // Height
    //SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
}
static void makeMazeAscii(Maze& maze, MapArt& map)
{
    int ii = 0;
    int jj = 0;
    int iii = 0;
    int jjj = 0;
    for (int i = 0; i < maze.maze.size(); i++)
    {
        //cout << "i: " << i << endl;
        for (int j = 0; j < maze.maze[0].size(); j++)
        {
            //cout << "j: " << j << endl;
            //cout << "maze block: " << maze.maze[i][j] << endl;
            if (maze.maze[i][j] == '*')
            {
                iii = 0;
                for (ii = i * 12; ii < (i * 12) + 12; ii++)
                {
                    jjj = 0;
                    for (jj = j * 25; jj < (j * 25) + 25; jj++)
                    {
                        map.map[ii][jj] = map.block[iii][jjj++];
                        //cout << "Bjj: " << jj << endl;
                    }
                    ++iii;
                    //cout << "Bii: " << ii << endl;
                }
            }
            else if (maze.maze[i][j] == 'S')
            {
                iii = 0;
                for (ii = i * 12; ii < (i * 12) + 12; ii++)
                {
                    jjj = 0;
                    for (jj = j * 25; jj < (j * 25) + 25; jj++)
                    {
                        map.map[ii][jj] = map.start[iii][jjj++];
                        //cout << "Bjj: " << jj << endl;
                    }
                    ++iii;
                    //cout << "Bii: " << ii << endl;
                }
            }
            else if (maze.maze[i][j] == 'P')
            {
                iii = 0;
                for (ii = i * 12; ii < (i * 12) + 12; ii++)
                {
                    jjj = 0;
                    for (jj = j * 25; jj < (j * 25) + 25; jj++)
                    {
                        map.map[ii][jj] = map.player[iii][jjj++];
                        //cout << "Bjj: " << jj << endl;
                    }
                    ++iii;
                    //cout << "Bii: " << ii << endl;
                }
            }
            else if (maze.maze[i][j] == 'E')
            {
                iii = 0;
                for (ii = i * 12; ii < (i * 12) + 12; ii++)
                {
                    jjj = 0;
                    for (jj = j * 25; jj < (j * 25) + 25; jj++)
                    {
                        map.map[ii][jj] = map.end[iii][jjj++];
                        //cout << "Bjj: " << jj << endl;
                    }
                    ++iii;
                    //cout << "Bii: " << ii << endl;
                }
            }
            else
            {
                iii = 0;
                for (ii = i * 12; ii < (i * 12) + 12; ii++)
                {
                    jjj = 0;
                    for (jj = j * 25; jj < (j * 25) + 25; jj++)
                    {
                        map.map[ii][jj] = map.emptySpace[iii][jjj++];
                        //cout << "Bjj: " << jj << endl;
                    }
                    ++iii;
                    //cout << "Bii: " << ii << endl;
                }
            }
        }
    }
}
static void solveMaze(Maze& maze, MapArt& map)
{
    int row, column;
    tie(row, column) = maze.location;
    while (haveNotWon(maze, map))
    {
        if (canGoLeft(maze, map))
        {
            if (isAtStart(maze, map))
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
        else if (canGoDown(maze, map))
        {
            if (isAtStart(maze, map))
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
        else if (canGoUp(maze, map))
        {
            if (isAtStart(maze, map))
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
        else if (canGoRight(maze, map))
        {
            if (isAtStart(maze, map))
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
        else  if (canGoBackRight(maze, map))
        {
            maze.maze[row][column--] = '-';
            maze.maze[row][column] = 'P';
            maze.location = make_tuple(row, column);
        }
        else if (canGoBackUp(maze, map))
        {
            maze.maze[row--][column] = '/';
            maze.maze[row][column] = 'P';
            maze.location = make_tuple(row, column);
        }
        else if (canGoBackDown(maze, map))
        {
            maze.maze[row++][column] = '/';
            maze.maze[row][column] = 'P';
            maze.location = make_tuple(row, column);
        }
        else if (canGoBackLeft(maze, map))
        {
            maze.maze[row][column++] = '-';
            maze.maze[row][column] = 'P';
            maze.location = make_tuple(row, column);
        }

        if (haveWon(maze, map))
        {
            cout << "You have won!" << endl;
            return;
        }
        makeMazeAscii(maze, map);
        printf("\033c");
        displayMazeAscii(map);
        cout << "Press any key to continue..." << std::endl;
        _getch();
        cout << "Key pressed. Program continues." << std::endl;
        printf("\033c");
        displayMazeAscii(map);
    }
}

static bool haveNotWon(Maze& maze, MapArt& map) 
{

    int row, column;
    tie(row, column) = maze.location;
    return !(maze.maze[row][column + 1] == 'E' || maze.maze[row + 1][column] == 'E' ||
        maze.maze[row - 1][column] == 'E' || maze.maze[row][column - 1] == 'E');
}
static bool haveWon(Maze& maze, MapArt& map)
{

    int row, column;
    tie(row, column) = maze.location;
    return (maze.maze[row][column + 1] == 'E' || maze.maze[row + 1][column] == 'E' ||
        maze.maze[row - 1][column] == 'E' || maze.maze[row][column - 1] == 'E');
}

static bool canGoLeft(Maze& maze, MapArt& map)
{

    int row, column;
    tie(row, column) = maze.location;
    return (maze.maze[row][column + 1] == ' ');
}
static bool canGoDown(Maze& maze, MapArt& map)
{

    int row, column;
    tie(row, column) = maze.location;
    return (maze.maze[row + 1][column] == ' ');
}
static bool canGoUp(Maze& maze, MapArt& map)
{

    int row, column;
    tie(row, column) = maze.location;
    return (maze.maze[row - 1][column] == ' ');
}
static bool canGoRight(Maze& maze, MapArt& map)
{

    int row, column;
    tie(row, column) = maze.location;
    return (maze.maze[row][column - 1] == ' ');
}
static bool isAtStart(Maze& maze, MapArt& map) 
{
    int row, column;
    tie(row, column) = maze.location;
    return tie(maze.location) == tie(maze.start);
}
static bool canGoBackRight(Maze& maze, MapArt& map)
{

    int row, column;
    tie(row, column) = maze.location;
    return (maze.maze[row][column - 1] == '_');
}
static bool canGoBackDown(Maze& maze, MapArt& map)
{

    int row, column;
    tie(row, column) = maze.location;
    return (maze.maze[row + 1][column] == '|');
}
static bool canGoBackUp(Maze& maze, MapArt& map)
{

    int row, column;
    tie(row, column) = maze.location;
    return (maze.maze[row - 1][column] == '|');
}
static bool canGoBackLeft(Maze& maze, MapArt& map)
{

    int row, column;
    tie(row, column) = maze.location;
    return (maze.maze[row][column + 1] == '_');
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
