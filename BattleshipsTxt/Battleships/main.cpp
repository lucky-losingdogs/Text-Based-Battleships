#include "main.h"


EndType UpdateGameState(GameState& gameState, vector<Ship>& ships, vector<Ship>& ships02, int shipsSize);

int main()
{
	GameState gameState = {0, 0, 1, true};			//initialise game state
	
	while (gameState.running)
	{
		system("title Battleships");			//changes console window title to "Battleships"

		printTitle(); 
		
		PlaySoundF(L"OOT_PressStart.wav");
		
		vector<Ship> ships = Ship::InitialiseShips();		//initialise player 1 ships class
		vector<Ship> ships02 = Ship::InitialiseShips();		//initialise player 2 ships class

		int shipsSize = ships.size();

		PlacingShips(ships, shipsSize, 1, gameState);		//player 1 ship selection
		PlacingShips(ships02, shipsSize, 2, gameState);	//player 2 ship selection

		

		EndType winState = UpdateGameState(gameState, ships, ships02, shipsSize);
		return winState;
	}

	return quit;
}

EndType UpdateGameState(GameState &gameState, vector<Ship> &ships, vector<Ship> &ships02, int shipsSize)
{
	while(gameState.running)
	{
		DestroyingShips(ships, ships02, shipsSize, 1, gameState);		//player 1 destroying ships
		DestroyingShips(ships02, ships, shipsSize, 2, gameState);		//player 2 destroying ships


		//increment players' ships destroyed values
		for (int i = 0; i < shipsSize; i++)
		{
			if (ships[i].destroyed && !ships[i].destroyedCounted)
			{
				gameState.player01ShipsDestroyed++;
				ships[i].destroyedCounted = true;
			}
			if (ships02[i].destroyed && !ships02[i].destroyedCounted)
			{
				gameState.player02ShipsDestroyed++;
				ships02[i].destroyedCounted = true;
			}
		}

		gameState.rounds++;

		//check for win state (if all of one player's ships is destroyed)
		if (gameState.player01ShipsDestroyed == shipsSize)
		{
			printWin();
			PlaySoundF(L"OOT_Fanfare_HeartContainer.wav");

			cout << ">>All of Player 1's ships are destroyed! Player 2 wins!\n>>This game took " << gameState.rounds << " rounds.\n";
			return player01Win;
		}
		else if (gameState.player02ShipsDestroyed == shipsSize)
		{
			printWin();
			PlaySoundF(L"OOT_Fanfare_HeartContainer.wav");

			cout << ">>All of Player 2's ships are destroyed! Player 1 wins!\n>>This game took " << gameState.rounds << " rounds.\n";
			return player02Win;
		}
		else if (gameState.player01ShipsDestroyed == shipsSize && gameState.player02ShipsDestroyed == shipsSize)
		{
			printTie();
			PlaySoundF(L"splash.wav");

			cout << ">>Both player ships have been destroyed! This game ends in a tie.\n>>This game took " << gameState.rounds << " rounds.\n";
			return playerTie;
		}
	}

	return quit;
}