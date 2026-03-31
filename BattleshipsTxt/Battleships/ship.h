#ifndef ship_h
#define ship_h
#include "include.h"

class Ship		//holds ship variables and initialised the 4 ships
{
public:
	//member var declarations
	const string name;
	const int size;
	
	int firstX;
	char firstY;
	int lastX;
	char lastY;

	vector<pair<int, char>> coordinates;
	vector<pair<int, char>> destroyedCoordinates;
	vector<pair<int, char>> missedMissileCoordinates;
	
	bool placed = false;
	bool destroyed = false;

	bool destroyedCounted = false;


	//function declarations
	static vector<Ship> InitialiseShips();
	static void PlaceShip(vector<Ship>& ships, int index);
	static void ChangeCoordinateShip(vector<Ship>& ships, int index, int firstx, char firsty, int lastx, char lasty, vector<pair<int, char>> newCoords);
	static void ChangeDestroyedCoordinate(vector<Ship>& ships, int index, int inputX, char inputY);
	
	

	//constructor
	Ship(string n, int o) : name(n), size(o), firstX(0), firstY('A'), lastX(0), lastY('A') {};
};

#endif // ship.h