#ifndef include_h
#define include_h

#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <vector>
#include <sstream>
#include <fstream>

//https://stackoverflow.com/questions/42819725/visual-c-or-c-play-sounds
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

using namespace std;


struct GameState
{
	int player01ShipsDestroyed;
	int player02ShipsDestroyed;
	int rounds;
	bool running;
};

enum EndType
{
	player01Win = 1,
	player02Win = 2,
	playerTie = 3,
	quit = 10
};

//enum to pass by parameter to choose whether to markchooseship or markdestroyship on the grid
enum MarkGridType
{
	GridChooseShip = 1,
	GridDestroyShip = 2
};


enum ConvertType
{
	toInt,
	toChar
};


//waits then clears the screen
inline void ClearScreen()
{
	Sleep(1600);
	system("CLS");
}

inline void SetColour(int colour)
{
	cout << "\x1b[" << colour << "m";
}

inline void ClearColour()
{
	cout << "\x1b[0m";
}

extern int userInput;
extern int userInputX;
extern char userInputY;

extern int gridNumbers[10];
extern string gridLetters[10];
extern string gridLettersCheck;

#endif // include_h