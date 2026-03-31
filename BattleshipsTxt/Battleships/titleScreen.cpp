#include "titleScreen.h"

void printTitle()
{
	ifstream titleFile = ifstream("title.txt");
	string line = "";

	while (getline(titleFile, line))
		cout << line << endl;

	titleFile.close();

	cout << "\n>>Enter any key to continue\n";

	string dummy;
	getline(cin, dummy);
	system("CLS");
}

void printWin()
{
	ifstream winFile = ifstream("win.txt");
	string line = "";
	
	while (getline(winFile, line))
		cout << line << endl;

	winFile.close();
}

void printTie()
{
	ifstream tieFile = ifstream("tie.txt");
	string line = "";

	while (getline(tieFile, line))
		cout << line << endl;

	tieFile.close();
}