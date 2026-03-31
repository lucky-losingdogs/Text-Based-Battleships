#include "placeShip.h"
#include "ship.h"
#include "grid.h"
#include "userInput.h"

//driving function for placing ships
void PlacingShips(vector<Ship>& ships, int shipsSize, int playerNumber, GameState& gameState)
{
	cout << ">>Player " << playerNumber << ":\n\n";
	DrawGrid(ships, shipsSize, MarkGridType::GridChooseShip);

	//placing 4 ships
	ChooseShip(ships, shipsSize, gameState);
	ClearScreen();
	DrawGrid(ships, shipsSize, MarkGridType::GridChooseShip);

	ChooseShip(ships, shipsSize, gameState);
	ClearScreen();
	DrawGrid(ships, shipsSize, MarkGridType::GridChooseShip);

	ChooseShip(ships, shipsSize, gameState);
	ClearScreen();
	DrawGrid(ships, shipsSize, MarkGridType::GridChooseShip);

	ChooseShip(ships, shipsSize, gameState);
	ClearScreen();
	DrawGrid(ships, shipsSize, MarkGridType::GridChooseShip);

	cout << "\n>>Player " << playerNumber << " ship selection complete!";
	PlaySoundF(L"OOT_PressStart.wav");
	ClearScreen();
}


void ChooseShip(vector<Ship>& ships, int shipsSize, GameState& gameState)
{

	cout << "\n>>Choose a ship:\n";

	for (int i = 0; i < shipsSize; i++)		//iterates through the array, printing the name of each ship and the size
	{
		cout << "[" << i << "] " << ships[i].name << " | Size: " << ships[i].size << endl;
	}

	while (true)
	{
		int tempX;
		char tempY;

		TakeInput(0, shipsSize - 1, ships, gameState, tempX, tempY, toInt);

		int userInput = tempX;
		if (CheckShipPlaced(ships, userInput))
		{
			continue;
		}


		switch (userInput)			//depending on input, a case is selected and prints its contents
		{
		case 0:
			cout << "\n>>" << ships[0].name << " selected.\n";
			break;
		case 1:
			cout << "\n>>" << ships[1].name << " selected.\n";
			break;
		case 2:
			cout << "\n>>" << ships[2].name << " selected.\n";
			break;
		case 3:
			cout << "\n>>" << ships[3].name << " selected.\n";
			break;
		default:
			cout << "\n>>That input was not recognised, please choose another ship:\n>";
			break;
		}

		ChooseCoord(ships, shipsSize, userInput, gameState);
		break;
	}

}

void ChooseCoord(vector<Ship>& ships, int shipsSize, int shipIndex, GameState& gameState)
{
	int inputStartX, inputEndX = 0;
	char inputStartY, inputEndY;
	int length = 0;

	while (true)
	{
		//receives input x and y coordinates for front and end of ships
		cout << "\n>>Choose the x and y coordinates for the front of the ship:";
		CheckValidXY(inputStartX, inputStartY, ships, gameState);

		cout << "\n>>Choose the x and y coordinates for the end of the ship:";
		CheckValidXY(inputEndX, inputEndY, ships, gameState);

		bool horizontal = (inputStartY == inputEndY);
		bool vertical = (inputStartX == inputEndX);

		//checks if the coords don't result in a vertical or horizontal line
		if (!horizontal && !vertical)
		{
			cout << ">>Invalid placement! Coordinates must be in a straight line, please try again:\n";
			continue;
		}

		//calculating length based on given coords
		if (horizontal)
		{
			length = abs(inputEndX - inputStartX) + 1;		//length if horizontal
		}
		else
		{
			length = abs(inputEndY - inputStartY) + 1;		//length if vertical
		}

		//checks if length is valid compared to ship size
		if (length != ships[shipIndex].size)
		{
			cout << ">>Invalid ship length! " << ships[shipIndex].name << " is " << ships[shipIndex].size << " units long. Please try again:\n";
			continue;
		}


		//initialising the coords as a vector
		vector<pair<int, char>> newCoords;

		if (horizontal)
		{
			int minX = min(inputStartX, inputEndX);
			int maxX = max(inputStartX, inputEndX);

			for (int x = minX; x <= maxX; x++)
			{
				newCoords.push_back({ x, inputStartY });
				//adds the x coordinate and y coordinate to the top of the newCoord vector
				//bc horizontal, y coord doesn't change, and x increments by 1 for each coord
			}
		}
		else if (vertical)
		{
			int minY = min(inputStartY, inputEndY);
			int maxY = max(inputStartY, inputEndY);

			for (int y = minY; y <= maxY; y++)
			{
				newCoords.push_back({ inputStartX, (char)y });		//converts y to char equivalent
			}
		}


		//checking for coord overlap
		bool overlapFound = false;

		for (int i = 0; i < shipsSize; i++)
		{
			if (!ships[i].placed)
				continue;

			for (int a = 0; a < ships[i].coordinates.size(); a++)
			{
				for (int b = 0; b < newCoords.size(); b++)
				{
					//if the indexed ship coord is equal to the indexed newCoord, there is overlap. first is x, second is y
					if (ships[i].coordinates[a].first == newCoords[b].first && ships[i].coordinates[a].second == newCoords[b].second)
					{
						overlapFound = true;
						break;		//series of breaks to break out of the 3 for loops
					}

					if (overlapFound)
						break;
				}

				if (overlapFound)
					break;
			}
		}

		//checks if overlap was found, if true, returns to original while(true) loop to re-enter coords
		if (overlapFound)
		{
			cout << "\n>>Invalid placement due to overlap! Please try again:\n";
			continue;
		}

		Ship::ChangeCoordinateShip(ships, shipIndex, inputStartX, inputStartY, inputEndX, inputEndY, newCoords);		//changing the values of the member variables of the ship coords
		Ship::PlaceShip(ships, shipIndex);			//calls the PlaceShip function, passing the index number to mark the placed member variable for that ship as true
		cout << ships[shipIndex].name << ": (" << ships[shipIndex].firstX << ", " << ships[shipIndex].firstY << ") to (" << ships[shipIndex].lastX << ", " << ships[shipIndex].lastY << ")\n";
		break;
	}

}