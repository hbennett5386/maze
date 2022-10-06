/*******************************************************************************************
* This program will read a file of which the first line will set the size of a maze.       *
* The rest of the file will determine what does in that maze. The maze will be built with  *
* the character 'X' signifying a wall, 'O' signifying a space that can be explored, '*'    *
* signifying a space that has been previously explored, and 'E' signifying the exit.       *
* It will then use recursion and backtracking to find the way through the maze to the exit *
* and will show the progress along the way, terminating when the exit is found or giving a *
* notification if no exit exists or the exit is unreachable (surrounded by walls).         *
*******************************************************************************************/
#include "maze.h"
#include<iostream>
#include<string>
using namespace std;

//Reads in the file, sets the size of the maze, creates the maze,
//and creates a border.
Maze::Maze(ifstream& inFile)
{
    //reading in size of maze
    inFile >> maxRows >> maxCols;
    //reading in the map
    for(int i = 1; i < maxRows+1; i++)
    {
        for(int j = 1; j < maxCols+1; j++)
        {
            inFile >> maze[i][j];
        }
    }
    //creating border
    for(int i = 0; i <= maxRows + 1; i++)
    {
        for(int j = 0; j <= maxCols + 1; j++)
        {
            maze[0][j] = 'X';
            maze[maxRows + 1][j] = 'X';
        }
    }
}
//Will display the current state of the maze
void Maze::Print()
{
    cout << "Maze state:" << endl;
    for(int i = 1; i < maxRows+1; i++)
    {
        for(int j = 1; j < maxCols+1; j++)
        {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}
//Will first check to see if the current position is the exit.
//If it is the exit, it will mark the exit as true, and will exit the function
//returning to the main function. If the current position contains a searchable 
//position, it will be marked, and the function will be called again, changing the 
//orientation until the exit is found. 
void Maze::FindExit(int rows, int cols, bool& exit)
{
    //check if on exit
    if(maze[rows][cols]== 'E')
    {
        exit = true;
        cout << "Trying " << rows << "," << cols << endl;
    }
    //if not on exit, begin calling recursively until on exit
    //or every position has been checked and there is no exit
    else if(maze[rows][cols] == 'O')
    {
        cout << "Trying " << rows << "," << cols << endl;
        maze[rows][cols] = '*';
        Print();
        if(!exit)
        {
            FindExit(rows, cols + 1, exit);
        }
        if(!exit)
        {
            FindExit(rows + 1, cols, exit);
        }
        if(!exit)
        {
            FindExit(rows, cols - 1, exit);
        }
        if(!exit)
        {
            FindExit(rows - 1, cols, exit);
        }
    }
}
