#include "grid.h"
#include "ship.h"


//driver grid printing loop
void DrawGrid(vector<Ship>& ships, int shipsSize, MarkGridType markGridType)
{

	const int rows = 10;
	const int columns = 10;

	vector<vector<char>> grid(rows, vector<char>(columns, '~'));		//10 rows, 10 columns, initialised to ~ character

	//enum to choose whether to markchooseship or markdestroyship
	if (markGridType == MarkGridType::GridChooseShip)
	{
		MarkChooseShip(ships, shipsSize, grid);
	}
	else if (markGridType == MarkGridType::GridDestroyShip)
	{
		MarkDestroyShip(ships, shipsSize, grid);
	}



	cout << " ";

	for (int i = 0; i < columns; i++)
	{
		cout << gridNumbers[i] << " ";
	}

	cout << endl;

	for (int r = 0; r < rows; r++)		//iterates until 10 rows
	{

		cout << gridLetters[r];

		for (int c = 0; c < columns; c++)		//iterates until 10 columns
		{
			SetColour(36);
			cout << grid[r][c] << " ";			//prints wherever the indexes are in the vector. because the vector is initialised to 0, it just prints 0
			ClearColour();
		}

		cout << endl;

	}
}

//marking where the ship coords are
void MarkChooseShip(vector<Ship>& ships, int shipsSize, vector<vector<char>>& grid)
{
	//marks the coordinates where the ships are with the 'o' char
	for (int i = 0; i < shipsSize; i++)
	{
		if (!ships[i].placed)
			continue;

		for (int a = 0; a < ships[i].coordinates.size(); a++)
		{
			int rowNumber = ships[i].coordinates[a].first - 1;				//converts x coord to start from 1 instead of 0
			int colNumber = ships[i].coordinates[a].second - 'A';		//converts y char to equivalent number (a = 1)
			grid[colNumber][rowNumber] = 'o';
		}

		for (int a = 0; a < ships[i].destroyedCoordinates.size(); a++)
		{
			int rowNumber = ships[i].destroyedCoordinates[a].first - 1;
			int colNumber = ships[i].destroyedCoordinates[a].second - 'A';
			grid[colNumber][rowNumber] = 'x';
		}

	}
}


//marking the missile results
void MarkDestroyShip(vector<Ship>& ships, int shipsSize, vector<vector<char>>& grid)
{
	//marks the coordinates where the missiles have landed, x if hit, \ if miss
	for (int b = 0; b < ships[0].missedMissileCoordinates.size(); b++)
	{
		int missRowNumber = ships[0].missedMissileCoordinates[b].first - 1;;
		int missColNumber = ships[0].missedMissileCoordinates[b].second - 'A';
		grid[missColNumber][missRowNumber] = '/';
	}


	for (int i = 0; i < shipsSize; i++)
	{

		for (int a = 0; a < ships[i].destroyedCoordinates.size(); a++)
		{
			int rowNumber = ships[i].destroyedCoordinates[a].first - 1;
			int colNumber = ships[i].destroyedCoordinates[a].second - 'A';
			grid[colNumber][rowNumber] = 'x';
		}

	}
}