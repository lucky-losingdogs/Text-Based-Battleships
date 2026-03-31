#include "destroyShip.h"
#include "userInput.h"
#include "ship.h"
#include "grid.h"

//driver function for destroying ships
void DestroyingShips(vector<Ship>& ships, vector<Ship>& ships02, int shipsSize, int playerNumber, GameState& gameState)
{
	cout << ">>Number of Player 1's ships destroyed: " << gameState.player01ShipsDestroyed << "\n";
	cout << ">>Number of Player 2's ships destroyed: " << gameState.player02ShipsDestroyed << "\n\n";

	cout << ">>Round: " << gameState.rounds << "\n>>Player " << playerNumber << ":\n";

	cout << "\nMissile grid:\n";
	DrawGrid(ships02, shipsSize, MarkGridType::GridDestroyShip);		//displays missile grid1

	cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-\n";
	cout << "\nYour ship grid:\n";
	DrawGrid(ships, shipsSize, MarkGridType::GridChooseShip);			//displays own grid


	ChooseDestroy(ships, ships02, shipsSize, gameState);
	ClearScreen();
}

void ChooseDestroy(vector<Ship>& ships, vector<Ship>& ships02, int shipsSize, GameState& gameState)
{
	int inputX = 0;
	char inputY;
	int correctShip = 0;


	while (true)
	{
		cout << "\n>>Choose a coordinate to send a missile at\n";
		CheckValidXY(inputX, inputY, ships, gameState);		//receives input x and y coordinates

		bool correctCoord = false;
		for (int i = 0; i < shipsSize; i++) //index through the 4 ships
		{
			//checks if the input coordinate matches a coordinate of the placed ship
			for (int a = 0; a < ships02[i].coordinates.size(); a++)
			{
				if (ships02[i].coordinates[a].first == inputX && ships02[i].coordinates[a].second == inputY)
				{
					correctCoord = true;
					correctShip = i;
					break;
				}
			}

			if (correctCoord)
				break;
		}


		if (correctCoord)
		{
			for (int i = 0; i < shipsSize; i++) //index through the 4 ships
			{
				//checks if the input coordinate = a destroyed coordinate
				for (int b = 0; b < ships02[i].destroyedCoordinates.size(); b++)
				{
					if (ships02[i].destroyedCoordinates[b].first == inputX && ships02[i].destroyedCoordinates[b].second == inputY)
					{
						cout << "\n>>Invalid coordinate, as that point has already been destroyed! Please try again:\n";
						correctCoord = false;
						correctShip = 1;
						break;
					}

				}

				if (!correctCoord)
				{
					break;
				}
				else if (correctCoord && i == correctShip) //if valid not destroyed coord
				{
					//pushback coord to destroyed coord vector, so can be checked later
					Ship::ChangeDestroyedCoordinate(ships02, i, inputX, inputY);
					cout << "\n>>Hit!\n\n";
					PlaySoundF(L"OOT_Bomb_Blow.wav");

					break;
				}
			}
		}


		//if all of the points in the ship is destroyed, the destroyed member var = true
		for (int i = 0; i < shipsSize; i++)
		{
			if (ships02[i].size == ships02[i].destroyedCoordinates.size())
			{
				ships02[i].destroyed = true;
				//when printing grids, the same coord will show up as an x on both players grids
			}

		}

		if (!(correctCoord) && (correctShip == 1))
		{
			continue;
		}

		//if wrong coord, end turn
		if (!correctCoord)
		{
			cout << "\nWhooosh!\n\n";
			PlaySoundF(L"splash.wav");

			ships02[0].missedMissileCoordinates.push_back({ inputX, inputY });
			//pushing which coord the missed missile went to the other player's variable
			//so when printing grid, the grid only needs to display the other player's stats


			return;
		}

		return;
	}

}