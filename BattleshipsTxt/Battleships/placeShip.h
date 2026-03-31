#ifndef placeShip_h
#define placeShip_h

#include "include.h"
#include "playSound.h"


class Ship;


void PlacingShips(vector<Ship>& ships, int shipsSize, int playerNumber, GameState& gameState);

void ChooseShip(vector<Ship>& ships, int shipsSize, GameState& gameState);

void ChooseCoord(vector<Ship>& ships, int shipsSize, int shipIndex, GameState& gameState);

#endif // placeShip.h