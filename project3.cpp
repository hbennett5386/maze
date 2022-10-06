/*******************************************************************************************
* This program will read a file of which the first line will set the size of a maze.       *
* The rest of the file will determine what does in that maze. The maze will be built with  *
* the character 'X' signifying a wall, 'O' signifying a space that can be explored, '*'    *
* signifying a space that has been previously explored, and 'E' signifying the exit.       *
* It will then use recursion and backtracking to find the way through the maze to the exit *
* and will show the progress along the way, terminating when the exit is found or giving a *
* notification if no exit exists or the exit is unreachable (surrounded by walls).         *
*******************************************************************************************/
#include<iostream>
#include"maze.h"
#include <fstream>
using namespace std;

//main function will set random to 1000 (not sure what this is used for in this program),
//open the input file to be read, print the current maze, set the bool exit to false, 
//display the starting position, and call the FindExit function which will recursively
//call itself until the exit is either found or it is determined that there is no exit or
//the exit is unreachable. It will then display the appropriate message and close the file. 
int main()
{
    srand(1000);
    ifstream inFile;
    inFile.open("maze.txt");
    Maze maze(inFile);
    maze.Print();
    bool exit = false;
    cout << "Start position: 1,1" << endl;
    maze.FindExit(1, 1, exit);
    if(exit)
    {
        cout << "Found exit!" << endl;
    }
    else
    {
        cout << "No exit found!" << endl;
    }
    inFile.close();
    return 0; 
}
