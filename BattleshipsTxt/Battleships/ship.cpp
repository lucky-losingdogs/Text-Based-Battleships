#include "ship.h"

//setting up ship variables with dynamic array
vector<Ship> Ship::InitialiseShips()		
{
	vector<Ship> ships =
	{
		{ "Small ship", 2},
		{ "Submarine", 3},
		{ "Battleship", 4},
		{ "Aircraft carrier", 5}
	};

	return ships;
}

//passing whether a ship has been placed by reference
void Ship::PlaceShip(vector<Ship>& ships, int index) 
{
	ships[index].placed = true;
}

//changes the coordinates of the each ship
void Ship::ChangeCoordinateShip(vector<Ship>& ships, int index, int firstx, char firsty, int lastx, char lasty, vector<pair<int, char>> newCoords)
{
	ships[index].firstX = firstx;
	ships[index].firstY = firsty;
	ships[index].lastX = lastx;
	ships[index].lastY = lasty;
	ships[index].coordinates = newCoords;
}

//keeps track of which coordinates have been destroyed
void Ship::ChangeDestroyedCoordinate(vector<Ship>& ships, int index, int inputX, char inputY)
{
	ships[index].destroyedCoordinates.push_back({ inputX, inputY });
}